inherit ROOM;

void create ()
{
  set ("short", "ʯ����");
  set ("long", @LONG

ʯ���ں����˵ģ���ɢ����һ��˵�������Ĺ�ζ��������֮��Ż��
��Χ��ϡ���������������������ż�˿Ѫ����
LONG);

          set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/beast" : 1,
]));

  set("exits", ([ /* sizeof() == 4 */
//  "east" : __DIR__"yujie2.c",
]));
//      
        set("water", 1);
//  
  setup();
}
