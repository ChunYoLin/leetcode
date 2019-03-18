class MyHashMap
{
    public:
        /** Initialize your data structure here. */
        struct entry
        {
            int key;
            int value;
            struct entry* next;
            entry(int _key, int _value, struct entry* _next):
                key(_key),
                value(_value),
                next(_next)
            {}
        };
        const static int table_size = 256;

        vector<struct entry*> table;

        MyHashMap()
        {
            table.resize(table_size, NULL); 
        }

        int logical_right_shift(int x, int nbits)
        {
            int mask = 1 << (32-nbits) - 1;
            return (x >> nbits) & mask;
        }

        int hash(int h)
        {
            // h ^= logical_right_shift(h, 20) ^ logical_right_shift(h, 12); 
            return h ^ logical_right_shift(h, 7) ^ logical_right_shift(h, 4);
        }

        /** value will always be non-negative. */
        void put(int key, int value)
        {
            int hash_key = hash(key);
            int idx = hash_key & (table.size()-1);
            for (struct entry* e = table[idx]; e != NULL; e = e->next)
            {
                if (e->key == key)
                {
                    e->value = value;
                    return;
                }
            }
            table[idx] = new entry(key, value, table[idx]);
        }

        /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
        int get(int key)
        {
            int hash_key = hash(key);
            int idx = hash_key & (table.size()-1);
            for (struct entry* e = table[idx]; e != NULL; e = e->next)
            {
                if (e->key == key)
                    return e->value;
            }
            return -1;

        }

        /** Removes the mapping of the specified value key if this map contains a mapping for the key */
        void remove(int key)
        {
            int hash_key = hash(key);
            int idx = hash_key & (table.size()-1);
            struct entry* pre = NULL;
            for (struct entry* e = table[idx]; e != NULL; e = e->next)
            {
                if (e->key == key)
                {
                    if (pre != NULL)
                        pre->next = e->next;
                    else
                        table[idx] = e->next;
                    delete e;
                    return;
                }
                pre = e;
            }
        }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */
