// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "�ĵ�");
  set ("long", @LONG

�����Ƿ��ɿ�һ������������Ь�꣬ר�۸�ʽ�������Ĳ�Ьľ
��Ƥѥ���������һЩ����֮�����Ʒ���������޻����˵
�����ѳ������귨ʦ�����õ��ݹ����档
    
LONG);

  set("exits", ([
        "south"    : __DIR__"jiedao3",
      ]));
  set("objects", ([
        __DIR__"npc/sg4" : 1,
      ]));
  setup();
}

