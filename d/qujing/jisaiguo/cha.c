#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

���еİ��������ƾɣ������ɾ����������˳������������ӡ���
��ǽ�ϻ����ż����ֻ�����������������Ȥ���ݺ����������
ҡ�ڣ�Ҷ�ӷ���������������
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"obj/qingzhutong" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "east": __DIR__"inner3",
]));

  setup();
}

