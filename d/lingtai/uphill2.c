// Room: some place in ��ţ����
// uphill2.c

inherit ROOM;

void create()
{
  set ("short", "����ƺ");
  set ("long", @LONG

ɽ·�������Ӷ��ϣ����ߵ����ֱ�ɽ��һ�������������졣
̧ͷ������ɽ�����ܣ���֪��Ҫ�߶�Զ����������ȥ������
̫����ʲôҲ���������ǰ��һ�ô�����(pine)�Ϻ���д��
Щʲô��
LONG);
  set("item_desc", ([ /* sizeof() == 1 */
  "pine" : "С���������ǣ�\n",
]));

set("exits", ([ /* sizeof() == 4 */
"northup" : __DIR__"uphill3",
"south": __DIR__"uphill1",
"west": __DIR__"forrest"
]));

        set("no_clean_up", 0);
	set("outdoors", 1);
        setup();
}

void init()
{
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{       
	object me;
        me=this_player();

        if ( !arg || ((arg != "pine") ))
                return notify_fail("��Ҫ��ʲô��\n");
        else
                message_vision("$Nץס�������֦��С�������������ȥ��\n",me);
                me->move("/d/lingtai/uptree");
		me->receive_damage("kee", 20);
		tell_room( environment(me), "��֦���˼��Σ��и�������������\n", ({me}));

                return 1;
}

