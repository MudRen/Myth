inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

�����Ƕ����������ϲ�һ�ܴ����罫��ֳ����룬��������
һЩ���СС�����Ƕ�����ӲʺУ������ǹ��ڵ������׭��ÿ��
����ʱ���ٲ������ǡ������Ĺ�ģ����������س��롣
LONG);
          set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zitaiwei" : 1,
  __DIR__"npc/qingdusi" : 1,
]));


  set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"mulang1.c",
  "north" : __DIR__"inside5",
  "southwest" : __DIR__"xizhen.c",
]));
//      
        set("water", 1);
//  
  setup();
}

