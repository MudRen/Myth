//Cracked by Roath
#include <room.h>
 inherit ROOM;
void create()
{
  set("short","���ݸ�����");
    set ("long", @LONG

����֮����һ������֮�ƣ����������ľ�������ǰ��һ�Ŵ���������
����֪�����ˡ�����һ�����ң�д�ţ������������ĸ��̽���֡���
������һλ��������
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"yamen",
  "west" : __DIR__"in",
]));

        set("no_fight", 1);
        set("no_magic", 1);
  set("light_up", 1);
  setup();
}
