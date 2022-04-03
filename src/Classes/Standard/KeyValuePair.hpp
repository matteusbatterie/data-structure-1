#pragma once

namespace Standard
{
    template <class TKey, class TValue>
    class KeyValuePair
    {
    private:
        TKey* _key;
        TValue* _value;

    public:
        KeyValuePair(TKey* key = nullptr, TValue* value = nullptr) {
            this->_key = key;
            this->_value = value;
        }
        KeyValuePair(TKey key, TValue value) {
            this->_key = new TKey(key);
            this->_value = new TValue(value);
        }
        ~KeyValuePair() {
            if (this->_key) delete this->_key;
            if (this->_value) delete this->_value;
        }

        TKey& key() const { return *(this->_key); }
        TValue& value() const { return *(this->_value); }
    };
}
