// Room: /d/sky/nantianmen
 
#include <room.h>
#include <ansi.h>
inherit ROOM;

void init();
void close_gate();
int do_knock(string);
int valid_leave();
string look_gate();

void create ()
{
  set ("short", "��ȸ��");
  set ("long", @LONG

������ȸ�ֻ���������������ʯʨ�ӣ�������ͷ���ţ�
������䣬����Ͱ��������������������,���������ɷ
һɫˮĥȺǽ�������ʯ̨����������ݻ���.����һ����
��ѩ�׷�ǽ,���滢Ƥʯ,������ȥ����Ȼ���ƷǷ�����ǰ
�����ż����������ݵĻ���١�
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south"     : __DIR__"zhangyuegong",
  "north"     : __DIR__"xuanyuantang",

]));



  set("objects", 
      ([
       __DIR__"npc/hgweishi" : 4,
      ]));


  setup();
}
 
