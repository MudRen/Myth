#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "ի��");
  set ("long", @LONG

���еİ��������ƾɣ������ɾ����������˳������������ӡ���
��ǽ�ϻ����ż����ֻ�����������������Ȥ���ݺ����������
ҡ�ڣ�Ҷ�ӷ���������������
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"obj/tanggao" : 1,
  __DIR__"obj/xiangsu" : 1, 
  __DIR__"obj/youshi" : 1, 

]));
  set("exits", ([ /* sizeof() == 2 */
  "west": __DIR__"inner3",
]));

  setup();
}

