// created by kuku@sjsh 2002/12

inherit ROOM;

void create ()
{
    set ("short", "��Զ�ھ�");
  set ("long", @LONG

��������Զ�ھ֣���ֻ̫ʦ��һ���ſ���������������
��ͷ���ֳ��̴������ڱ�Ŀ��˼��ǽ�Ϲ��ż����ֻ�
��һ�ѱ�����
LONG);

    set("exits", ([ 
        "north"    : "/d/qujing/qinfa/jiedao7",
      ]));
    set("objects", ([ 
        __DIR__"npc/baobiao"    : 1,
      ]));
  setup();
}
