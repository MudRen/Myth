// boy3.c

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

����һ�������������ϰڵĶ���Щɽ�亣ζ��̫�����ͼ�������
�Ⱦơ���Ů�������ϲˣ�����һƬ��ζ��
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"boy2",
]));
  set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/long2.c" : 1,
  __DIR__"npc/longshao" : 1,
  __DIR__"npc/biaodi" : 1,
]));
//      
        set("water", 1);
//  
  setup();
}
