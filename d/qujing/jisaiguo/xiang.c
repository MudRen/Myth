#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

���к�����ģ����ϵ����͵Ʋ�֪�����˶������ˡ�������ɢ��
������ζ��ȴ����̫������������¼����������ѽ�����ҧ����
�ò��������Թҵ�����Ҳ�����Ʈ�������õĲ������ӡ�
LONG);

//  set("objects", ([ /* sizeof() == 1*/ 
//  __DIR__"npc/erlang" : 1,
//]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "east": __DIR__"inner2",
]));

  setup();
}

