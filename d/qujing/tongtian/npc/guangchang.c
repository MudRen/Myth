//Cracked by Roath
// Room: /d/nanhai/guangchan
inherit ROOM;

void create ()
{
  set ("short", "��ǰ�㳡");
  set ("long", @LONG

�����Ϻ�����ɽ��һ��Ƚ�ƽ�������أ�����ɽ���˵����Ǿ�
���������д����գ������𷨣������ĵá�
LONG);

  set("objects", ([ /* sizeof() == 2 */
  "/d/nanhai/npc/huian" : 1,
  "/d/nanhai/npc/zhangmen" : 1,
]));
  set("outdoors", "/d/nanhai");
  set("valid_startroom", 1);
  set("exits", ([ /* sizeof() == 4 */
  "south" : "/d/nanhai/xiaoyuan",
  "west" : "/d/nanhai/zoulang",
  "east" : "/d/nanhai/road1.c",
  "enter" : "/d/nanhai/chaoyindong",
]));

  setup();
}
void init()
{
	add_action("do_back", "back");
}
int valid_leave(object me, string dir)
{
	if (dir == "enter" )
	{
	  if(me->query("obstacles/tongtian")=="guanyin")
	    return notify_fail("�����ڽ������ܼ��㣬�㵽����(back)ȥ�����ɣ�\n");
	}
return 1;
}

int do_back(string arg)
{
	object me = this_player();
	if (arg) return 0;
	if( me->query("obstacles/tongtian")!="won") return 0;
	if (me->is_busy()) return notify_fail("����æ������˵Ҳ�����\n");
	me->move("/u/opal/qujing/tongtian/lianting");		
	return 1;
}
