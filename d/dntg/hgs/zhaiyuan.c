// Room: /d/4world/zhaiyuan.c
inherit ROOM;

void create()
{
  set ("short", "իԺ");
  set ("long", @LONG

һ��СС��Ժ�䣬Ժ�в���ȴ��ʰ�ظɸɾ�����Ժ��ɢ������
ľ�������ϰ���Щ���֮�ࡣ����̨�����˸���ͷ��̨�ϰ��˿�
����������������Ҫ�Ƕ��˵Ļ���������Ҫ(yao)�Եġ�
LONG);
  set("outdoors", "/d/4world");
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"west1",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/laotou" : 1,
  "/d/obj/food/baozi" : 2,
  "/d/obj/food/chahu" : 1,
]));
//  set("no_fight", 1);
//  set("no_magic", 1);
  set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));

  setup();
}

int valid_leave()
{
        if((present("bao", this_player())))
            return notify_fail("��ͷ����˵�����������������Ĺ�أ�\n");
	if(present("teapot", this_player()) )	
            return notify_fail("��ͷ����˵������ҵĲ�������ˣ�\n");
    return ::valid_leave();
}

