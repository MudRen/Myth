//Cracked by Roath
inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

������һƬ��ڣ�ͷ�������������������ס�˹��ߣ������ѱ�
�����ϱ�����紵������������������ȴ�������˷�����
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"songlin4",
  "northwest" : __DIR__"songlin1",
  "southwest" : __DIR__"songlin4",
  "southeast" : __DIR__"songlin1",
]));

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/shanyao" : 1,
]));


  setup();
}

