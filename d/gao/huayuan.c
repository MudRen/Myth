// huayuan.c

inherit ROOM;

void create()
{
  set ("short", "��԰");
  set ("long", @LONG

��԰�л������࣬ʲô���ɡ����ڡ�������ٺϡ�Ǿޱ��ĵ����
�ȣ�����ö�٣���Ŀ���ǣ�������֮ʱ����԰�к�����ϣ�����
������������һ�ᣬ�úÿ�����
LONG);
set("item_desc",(["flower":
"Ư���Ļ�԰���˲ȵ����߰��㣬�ۼ�һֱͨ����ǽ�ߣ�����\n"
]));

set("exits", ([ /* sizeof() == 4 */
"south" : __DIR__"houyuan",
]));
	set("outdoors", 1);
        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_climb", "climb");
}
int do_climb(string arg)
{       object me;
        me=this_player();

        if ( !arg || ((arg != "wall") ))
                return notify_fail("��Ҫ��ʲô��\n");
if (me->query_temp("ridee"))
return notify_fail("��������û����ô�õı��£�\n");
                message_vision("$Nһ��ǽͷ�����˹�ȥ��\n", me);
                me->move("/d/gao/xiaolu");
/*
                me->set_temp("apply/dodge",0);
                me->set_temp("ride/dodge",0);
*/
// mudring Jan/03/2002
me->delete_temp("ridee");
me->set_temp("ride/dodge",0);
me->add_temp("apply/dodge",-me->query_temp("ride/dodge"));
		tell_room( environment(me), "�����ˡ�һ����" + me->name() + "��ǽͷ������������\n",
({me}) );
                return 1;
}

