//Cracked by Roath
// Room: /d/nanhai/zhaifang

#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "ի��");
  set ("long", @LONG

����������ɽ���˵����ǳԷ���ի�ĳ����������ϰ���һЩ
�߲�ˮ�������������ߴ����ɮ�ˣ����ի��ֻ�ṩ��ϯ��
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"zoulang2",
]));
  set("objects", ([ /* sizeof() == 4 */
  "/d/ourhome/obj/dhg" : 1,
  "/d/ourhome/obj/hulu" : 1,
  "/d/ourhome/obj/xbc" : 1,
  "/d/ourhome/obj/xqc" : 1,
]));
  set("light_up", 1);
  set("no_fight", 1);
  set("no_magic", 1);
  set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));

  setup();
}
