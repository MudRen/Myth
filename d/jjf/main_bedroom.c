// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /d/jjf/main_bedroom.c

inherit ROOM;

void create()
{
  set("short", "�Է�");
  set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
      );
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"main_cabinet2",
]));
  set("if_bed", 1);
  set("sleep_room",1);
  set("outdoors", 0);
  set("no_clean_up", 0);

  setup();
  replace_program(ROOM);
}
