//Cracked by Roath
// Room: /moon/ontop.c
//cglaem...12/13/96.

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

һ������״��С�ţ����������񣬾���ϸ�����ʻ������������Ϳ�Σ�һ
ɫˮĥȺǽ�������ʯ̨�ף����÷����������һ������ѩ�׷�ǽ������
��Ƥʯ��������ȥ���ſ���һ�����(tree)�������Բԡ��������䣬ȴ��
����ϰϰ�����˾���ˬ��
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "tree" : "һ��������ƵĴ���� �����������Ĺ�
��ɢ�����������㣬��֪���������ܲɼ�����
",
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"obj/guishuzhi" : 1,
  __DIR__"npc/girl" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"road1",
  "down" : __DIR__"tree2",
]));

  setup();
}


int valid_leave(object me, string dir)
{
	object wugang;
	
    if (me->query("gender") == "����" && dir == "north" ) {
        if(objectp(wugang=present("wu gang", environment(me))) && living(wugang) )
            return notify_fail("������ת����գ����һ�Ѵ�師��ס�����\n����...Ժ����ס��ȫ��Ů�ˣ����ܽ�ȥ���ʲô��\n");
    }
    return ::valid_leave(me, dir);
}
