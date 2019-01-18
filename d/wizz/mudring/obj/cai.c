// cai.c  

inherit ITEM;

string* titles = ({
        "��ĥ�ʼ�",             "����Ѽ��",             "��縼�˿",
        "ӣ�ٹ�ʿ�",           "С������ţ��",         "��Ƭ���ײ�",
        "������Ƥ�����",       "����������",           "ӣ����ɽҩ",           
        "�ջ������",           "��������",             "Ѽ���ﺣ��",
        "Ѽ���������",         "�մĹ�",               "��Ƭ������Ƭ",         
        "����˿���ܶ�˿",       "�ƾ²˳���",           "Ѭ�⻨С��",
        "Ѭ��˿",               "������",               "�����ͳ��ײ�˿",       
        "��������",             "��������",             "���˭������÷",
        "�Ǵ������",           "�Ͷ�������",           "��Ͳ������",
        "��˿�ǲ˵�",           "������︼�",           "������Ź�",
        "�ŷ���ȫ��",           "��֭���⸬",           "�����Ϻ��"
        "�������Ϻ",           "�����βϺ",           "�ඹţ��ĩ",
        "��Ͳ������",           "��������",             "��������",
        "���ں�����",           "����ţ��˿",           "ԭ��������",
        "�����㹽��",           "����ǽ",               "ܽ��з",
        "�˱�����",             "ը�ջ�Ϻ��",           "������Ҷ���",
        "����������",           "��������S",           "����Ѽ����",
        "�������S",             "��������",           "�빽��˿",
        "��˿ȫ��",             "��Ҷ�⼦",             "��������",
        "��䶹��",             "��������",             "�㸹������",
        "����ɱ�",             "�ʷ�צ",             "̫������",     
});


void create()
{
        int i = random(sizeof(titles));

        set_name(titles[i], ({ "cai", "xiaocai" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ��ʮ�ֿɿ�С�ˡ�\n");
                set("unit", "��");
                set("value", 3000);
                set("remaining", 4);
                set("food_supply", 40);
        }
        setup();
}
void init()
{
        add_action("do_eat", "eat");
}


int do_eat(string arg)
{
        object me,ob;
        int i;
        i = random(sizeof(titles));
        me = this_player();
        ob = this_object();

        if(!ob->id(arg) ) return 0;
        if(me->is_busy() )
                return notify_fail("����һ��������û����ɡ�\n");
        if( (int)me->query("food") >= (int)me->max_food_capacity() )
                return notify_fail("���Ѿ���̫���ˣ���Ҳ�Բ����ˡ�\n");
        set("value", 0);
        me->add("food", (int)query("food_supply"));
        if(me->is_fighting() ) me->start_busy(2);
        add("remaining", -1);
                
        if ( query("remaining") ){
                if ((string)me->query("gender") == "Ů��") 
                message_vision("$Nʮ�����ŵش����������һЩ" + ob->query("name") + "������С�\n", me);
                else
                message_vision("$N�����������һЩ" + ob->query("name") + "������У����̻��ʵس�������\n", me);
        }
        else    { 
                if ((string)me->query("gender") == "Ů��") 
                message_vision("$N�Թ��������" + ob->query("name") + "�����ó�һ��˿��������ز��˲��졣\n",me);
                else 
                message_vision("$N�������" + ob->query("name") + "���˾��⣬�ٰ��������˸��ɸɾ�����\n",me);
        destruct(ob);
        }
        return 1;
}



