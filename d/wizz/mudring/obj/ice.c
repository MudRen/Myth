// cigarette.c

inherit ITEM;

void init()
{
        add_action("do_smoke", "xiyan");
}

void create()
{
        string *order = ({"�л�","��ǰ��", "�������", "����ɽ", "��·", "ϣ����", 
"����", "ʥ����", "����", "����", "��Ϫ", "����", "capri", "ɳ��"});
        set_name( (order[random(sizeof(order))]), ({ "cigarette", "yan" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�����̣�����(xiyan)��\n");
                set("unit", "��");
                set("count",8);
                set("value", 50000);
        }
}


int do_smoke()
{
        object me = this_player();
        object obj = this_object();

        if(environment(me)->query("sleep_room"))
                return notify_fail("˯���ﲻ׼���̣�\n");
        if(environment(obj) != me)
                return notify_fail("�����ڿ��̰ɣ�\n");
        if(query("master") && query("master") != me->query("id"))
                return notify_fail("�����Ѿ���ȼ�ˣ����Ҳ�������̡�\n");
        add("count",-1);
        me->start_busy(1);
        me->add("combat_exp", 5);
        switch(query("count")) {
                case 1: message_vision("$N������һ��ʣ�µ���ƨ�ɣ�������ָ��סһ�����ӵ�����ͷ��\n", me);
                        break; 
                case 2: message_vision("$N�³�һ����Ȧ�����������е�ɢ����\n", me);
                        break;
                case 3: message_vision("$N�����۾������������һ��$n���ִӱǿ������������ˬ����ˬ������\n", me, obj);
                        break;
                case 4: message_vision("$N�ݺݵ�����һ��$n�����������̫���ˣ�һ�����ǵ�ͨ�졣\n", me, obj);
                        break;
                case 5: message_vision("$N����һ��$n��ҡͷ���Ե�˵����������һ֧�̣����������ɡ���\n", me, obj );
                        break;
                case 6: message_vision("$N��������ȣ������۾���������һ��$n����������������ⶫ�������ֺ�����Ϊɶ�һ���ôϲ������\n", me, obj);
                        break;
                case 7: set("master", me->query("id"));
                        message_vision("$N���һ֧$n�������˻������̵�����������\n", me, obj);
                        break;
                default:
                        break;
        }        
        if(query("count") > 1) call_out("do_smoke", 10);
        else destruct(obj);
        return 1;
}

