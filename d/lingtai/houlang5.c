// Room: some place in ��ţ����
// houlang5.c

inherit ROOM;

void create ()
{
        set ("short", "����ľ��");
        set ("long", @LONG

���ȵľ�ͷ�ֳ�һ��Сľ�ݣ�ľ�ݴ���߿�����������ΧҲ��
������������һ˿���졣��ֵ��Ǵ�ľ��ķ�϶��͸�������⡣
����һ��ľ�Ž��ա�
LONG);

        set("exits", ([ /* sizeof() == 2 */
                "southwest" : __DIR__"houlang4",
                "enter": __DIR__"room",
        ]));

        setup();
}
/*
void init()
{
        add_action("do_knock", "knock");
}

int do_knock(string arg)
{       
        object me;
        me=this_player();

        if ( !arg || ((arg != "door") ))
                return notify_fail("��Ҫ��ʲô��\n");

        message_vision("$N������������ϵ�ͭ������ž��ž���ؿ������¡�\n",me); 
        message_vision("�ű������������߳�λ������ˣ����´�����$Nһ����\n",me);
        if((string)me->query("family/family_name")=="����ɽ���Ƕ�") 
        {
                if(((int)me->query("combat_exp") < 100000)) 
                {
                        message_vision("������˶�$NЦ��������Ҳ���ݼ���ʦ��\n",me);
                        message_vision("$N��������������˽�ȥ��\n",me);
                        tell_room( environment(me), "��������Ĺ����ˡ�\n",({me}));
                        me->move("/d/lingtai/room");
                        tell_room( environment(me), me->name() + "���˽�����\n",({me}));
                        return 1;
                }
                message_vision("$N��������������˽�ȥ��\n",me);
                tell_room( environment(me), "��������Ĺ����ˡ�\n",({me}));
                me->move("/d/lingtai/room");
                tell_room( environment(me), me->name() + "���˽�����\n",({me}));
                return 1;
        }
        message_vision("�������������üͷ����Ī������������ʦ���ޣ�\n", me);
        message_vision("$N��������������˽�ȥ��\n",me);
        tell_room( environment(me), "��������Ĺ����ˡ�\n",({me}));
        me->move("/d/lingtai/room");
        tell_room( environment(me), me->name() + "���˽�����\n",({me}));


        return 1;

}


*/

