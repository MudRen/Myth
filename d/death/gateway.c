// Room: /d/death/gateway.c

inherit ROOM;

void create ()
{
  set ("short", "ۺ������");
  set ("long", @LONG

����������һ����ɫ��¥֮ǰ����¥�Ͽ����������֣�ۺ���ǡ���
���߽���¥ֻ��һƬ������ģ�ֻ��������ɫ�Ļ���������ֵ�
��˸�š�
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"gate",
  "north" : __DIR__"walk1",
]));
  set("hell", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/bgargoyle" : 1,
]));

  setup();
}

int valid_leave(object me, string dir)
{	me=this_player();

	if( wizardp(me)) return 1;

	if (dir == "north") {
		if((string)me->query("family/family_name")!="���޵ظ�") {
			if (objectp(present("black gargoyle", environment(me))))
				return notify_fail("���޳�����ȵ��������Ҵ���\n");
			if(me->is_ghost()){
				me->reincarnate();
			}
		return 1;				
		}
		if(me->is_ghost()){
			me->reincarnate();
		}
	return 1;
	}
	else return 1;
}


