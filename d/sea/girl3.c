// girl3.c

inherit ROOM;

void create ()
{
  set ("short", "�巿");
  set ("long", @LONG

������Ů��ס��������ڲ��õļ�����š���һ��������һ��
��ʹ�����Ե��������ʡ������ͼ���С��Ů��֪��Ц��ʲô��
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"girl2",
]));
  set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/long5" : 1,
  __DIR__"npc/gongnu" : 1,
  __DIR__"npc/longnu" : 1,
]));
//      
        set("water", 1);
//  
  setup();
}
