

#include <iostream>
#include <vector>
#define test() freopen("in", "r", stdin)

using namespace std;

vector<int> v;
// metaProgramming
template <long long i = 1>
class Fibonacci
{
  public:
    enum
    {
        value = Fibonacci<i - 1>::value + Fibonacci<i - 2>::value
    };
};

template <>
class Fibonacci<2>
{
  public:
    enum
    {
        value = 1
    };
};
template <>
class Fibonacci<1>
{
  public:
    enum
    {
        value = 1
    };
};

template <int p, int i>
struct PrimeMagicCube
{
    enum
    {
        answer = p % i && PrimeMagicCube<p, i - 1>::answer
    };
};
template <int p>
struct PrimeMagicCube<p, 1>
{
    enum
    {
        answer = 1
    };
};
template <int i>
struct Number
{
    Number<i - 1> a;
    enum
    {
        answer = PrimeMagicCube<i, i - 1>::answer
    };
    void IsPrime()
    {
        if (answer)
            v.push_back(i);
        a.IsPrime();
    }
};

template <>
struct Number<2>
{
    enum
    {
        answer = 1
    };
    void IsPrime()
    {
        v.push_back(2);
    }
};













// Event Templates


class Empty
{
};


template <typename EventAction>
class EventResponsor
{
  public:
    EventResponsor() : actor(NULL), action(NULL) {}
    EventResponsor(Empty *actor, EventAction *action) : actor(actor), action(action) {}
    friend bool operator==(const EventResponsor &lhs, const EventResponsor &rhs)
    {
        return lhs.actor == rhs.actor && *lhs.action == *rhs.action;
    }

  public: 
    Empty *actor;
    EventAction *action;
}; 


template <typename EventAction>
class Event
{
  public:
    typedef vector<EventResponsor<EventAction> > EventResponsors;
    typedef typename vector<EventResponsor<EventAction> >::iterator EventIterator;

  public:
    virtual ~Event()
    {
        for (EventIterator it = this->_ers.begin(); it != this->_ers.end(); ++it)
        {
            delete it->action, it->action = NULL;
        }
    }

    EventResponsors &GetResponsors() { return this->_ers; }

    template <typename Responsor, typename Action>
    void Bind(Responsor *actor, Action action)
    {
        Action *act = new Action(action);
        EventResponsor<EventAction> er((Empty *)actor, (EventAction *)act);
        bool unbound = true;
        for (EventIterator it = this->_ers.begin(); it != this->_ers.end(); ++it)
        {
            if (*it == er) 
            {
                unbound = false;
                break;
            }
        }
        if (unbound)
            this->_ers.push_back(er);
        else
            delete er.action, er.action = NULL;
    } 
    template <typename Responsor, typename Action>
    void Unbind(Responsor *actor, Action action)
    {
        Action *act = new Action(action);
        EventResponsor<EventAction> er((Empty *)actor, (EventAction *)act);
        for (EventIterator it = this->_ers.begin(); it != this->_ers.end(); ++it)
        {
            if (*it == er) 
            {
                delete it->action, this->_ers.erase(it);
                break;
            }
        }
        delete er.action, er.action = NULL;
    }

  private:
    EventResponsors _ers;
};


typedef Empty EventDelegator;
typedef void (EventDelegator::*ValueChanged)(int value, void *tag);


class Trigger
{
  public:
    Trigger() : _value(0) {}
    void SetValue(int value, void *tag);
    int GetValue() { return _value; }

  public:
    Event<ValueChanged> value_changed;

  private:
    int _value;
};


void Trigger::SetValue(int value, void *tag)
{
    if (_value == value)
        return;
    _value = value;
    Event<ValueChanged>::EventResponsors ers = this->value_changed.GetResponsors();
    if (!ers.empty())
    {
        Event<ValueChanged>::EventIterator it;
        for (it = ers.begin(); it != ers.end(); ++it)
        {
            ((it->actor)->*(*(it->action)))(value, tag); 
        }
    }
}


class Actor
{
  public:
    
    void Listen(Trigger *trigger)
    {
        trigger->value_changed.Bind(this, &Actor::OnValueChanged);
    }

    
    void Unlisten(Trigger *trigger)
    {
        trigger->value_changed.Unbind(this, &Actor::OnValueChanged);
    }

    
    void OnValueChanged(int value, void *tag)
    {
        cout << reinterpret_cast<char *>(tag) << value << "." << endl;
    }
};



int main(int argc, char const *argv[])
{
    /* code */
    const char *s = "Now the value is ";
    Trigger t;
    Actor a1, a2;

    a1.Listen(&t);
    a2.Listen(&t);

    cout << "Listening..." << endl;
    t.SetValue(10, reinterpret_cast<void *>(const_cast<char *>(s)));

    a2.Unlisten(&t);
    cout << "Listening again..." << endl;
    t.SetValue(20, reinterpret_cast<void *>(const_cast<char *>(s)));

    return 0;
}
