// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "իջ");
  set ("long", @LONG

իջԭΪ���ɿ�ӭ��ջ����ú����꣬ջ���㽫��ջ��Ϊիջ
��ʾ���֮���ġ�իջ��Ϊ������ṩ����ˮ������Ϊի�ң�
Ϊ·���ṩ�漢��Сʳ��
    
LONG);

  set("exits", ([
        "south"    : __DIR__"jiedao7",
        "north"    : __DIR__"zhaishi",
      ]));
  set("resource", ([
        "water"    : 1,
      ]));
  set("objects", ([
        __DIR__"npc/sg1" : 1,
      ]));
  set("valid_startroom",1);
  setup();
}

