// hill.c

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

����ʮ�ֿ���ǽ�ϻ�����һЩ�����ֽ⣬��ǽ�ļ����Ϸ���ʮ��
�ѳ�ǹ�������̵��ǲü������ľ�飬��������֨֨���졣

LONG);

  set("water", 1);
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/long3.c" : 1,
  __DIR__"obj/mucha" : 1,
//   "d/qujing/bibotan/npc/changtuixiabing" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"boy2",
]));
//      
        set("water", 1);
//  
  setup();
}
