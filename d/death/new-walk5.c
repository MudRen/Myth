// zhting.c

inherit ROOM;

void create ()
{
  set ("short", "��˾");
  set ("long", @LONG

����������ܵظ�֮�У�ż������������������˾��ǣ��Щ����
��������������ȥ����Χ��һ������¥�󹬵������Ҳ�൱�ĸ�
���ûʣ���ֵ��Ƕ���һ�ȶ��Ž𶤵ĺ�ľ�ź�һ�������ż���
LONG);
  set("item_desc", ([ /* sizeof() == 1 */
  "north" : "������Լ��������ɱ��ɭɭ��\n",
]));

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"new-walk2",
  "north" : "/d/death/zhengtang",
]));
  set("hell", 1);
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/mamian" : 1,
  __DIR__"npc/niutou" : 1,
]));

  setup();
}

int valid_leave(object me, string dir)
{       if (dir == "north") {
        if((string)me->query("family/family_name")!="���޵ظ�") {
	if (objectp(present("niutou gui", environment(me))))
        return notify_fail("ţͷ���ȼ������ô����޵�ⲻ��������\n");
        if (objectp(present("mamian gui", environment(me))))
        return  notify_fail("�������������ͭ����������˵������������Ӧ����\n");

	}

	return ::valid_leave(me, dir);
	}
	return ::valid_leave(me, dir);

}

