// Room: /d/death/road3.c

inherit ROOM;

void create()
{
        set("short", "�ڰ�֮��");
        set("long", @LONG

Ҳ��֪�ǵ������ֻ���������쳣��С���������Ҳ������࣮
�������ǲ����ܵģ�ʲôҲ��������ʲôҲ��������������
��һ�ɸ��õ�ζ����
LONG
        );
set("exits", ([ /* sizeof() == 4 */
]));

        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_open", "open");
}

int do_open(string arg)
{       
        object me;
        me=this_player();

        if ( !arg || ((arg != "guancai")&&(arg != "�ײ�") ) )
                return notify_fail("��Ҫ��ʲô��\n");
        else {
       
            message_vision("$N����һ���߿��ײģ����˳�ȥ��\n\n",me);
	    me->reincarnate();
	    me->set("gin", (int)me->query("max_gin"));
            me->move("/d/diyu/gufen");
            message_vision("\n���ϵ������˶���$N������ͷ���Ӳ����˳�����\n",me);
        }
                return 1;
}

