//Cracked by Roath
inherit ROOM;

void create ()
{
  set ("short", "���¹�");
  set ("long", @LONG

���ߵ�Сɽ�����������γ���һ������״��ɽ�ȡ����п�����
�಻֪����Ұ����������ʮ�ֵ����Ű������ȵı�����һƬ��
������ˮ��
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "southwest" : __DIR__"jiandi2",
  "north" : __DIR__"baihu", 
]));

  set("objects", ([ /* sizeof() == 1*/
  __DIR__"obj/qixingcao" : 1,
  __DIR__"obj/jinyinguo" : 1,    
  __DIR__"obj/xuanhuang" : 1,
]));

  set("outdoors", 1);


  setup();
}

