// Room: /d/wiz/menpai_room
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","����������");
  set ("long", @LONG

�����ǹ����μ���ʦ���������ɷ�չƽ��ȸ�������ġ�
LONG);
/*
���μ������������£�

�ɣ��Ϻ����ӣ�������̨
�����ݿ�ɽ�޵׶�����ѩɽ
�У����������¹����������ظ�
*/

  set("no_fight", 1);
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"jobroom",
]));
  set("light_up", 1);
  set("no_magic", 1);

  setup();
  call_other("/obj/board/menpai_bbs", "???");
//  call_other("/obj/board/kf_b", "???");
}
