inherit ROOM;

void create ()
{
  set ("short", "Ļ��");
  set ("long", @LONG

Ļ����������Ϻ��з������ˮ����Ϣ�ĵط�����ǰ�����ֺ��ָߵġ�����
���ӣ�������ǰ���ֿ������в��޻�����װ�Σ�����ɨ�ĺ޸ɾ���������
�м�������������롣
LONG);
          set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/gonge" : 1,
]));


  set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"qingxin",
  "east" : __DIR__"food.c",
]));
//      
        set("water", 1);
//  
  setup();
}

