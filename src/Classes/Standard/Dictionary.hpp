#pragma once
#include "./KeyValuePair.hpp"

namespace Standard
{
    template <class TKey, class TValue>
    class Dictionary
    {
    private:
        KeyValuePair<TKey, TValue>* _items;
        unsigned long _size;

    public:
        Dictionary() {
            this->_items = new KeyValuePair<TKey, TValue>[0];
            this->_size = 0;
        }
        Dictionary(KeyValuePair<TKey, TValue> items[], unsigned long size)
            : _items(items) {
            this->_size = size;
        }
        ~Dictionary() {
            delete this->_items;
        }

        unsigned long size() const { return this->_size; }

        TValue& item(TKey& key) const {
            for (unsigned int index = 0; index < _size; index++)
                if (_items[index].key() == key)
                    return _items[index].value();

            return nullptr;
        }

        TKey* keys() const {
            TKey keys[_size];
            for (unsigned int index = 0; index < _size; index++)
                keys[index] = _items[index].keys();

            return keys;
        }

        TValue* values() const {
            TValue values[_size];
            for (unsigned int index = 0; index < _size; index++)
                values[index] = _items[index].value();

            return values;
        }


        void add(TKey& key, TValue& value) {
            KeyValuePair<TKey, TValue>* newItems = new KeyValuePair<TKey, TValue>[++_size];

            for (unsigned int index = 0; index < _size - 1; index++)
                newItems[index] = _items[index];

            newItems[_size - 1] = KeyValuePair<TKey, TValue>(key, value);

            delete _items;
            _items = newItems;
        }

    private:
        void remove(TKey& key) {
            // to be implemented
        }
        void remove(TKey& key, TValue& value) {
            // to be implemented
        }
    };
}
