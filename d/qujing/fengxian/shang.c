// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "�Ϲٸ�");
  set ("long", @LONG

�Ϲٸ�λ�ڿ��ϣ���ǰ��˫ʨ���š����ڵƻ�ͨ�������Ҹ���
��������ʱ����ļ�̨����������������¯�������������ղ�
�ϣ���ʾ�ٸ�����ľ��ġ�
    
LONG);

  set("exits", ([
        "north"    : __DIR__"jiedao11",
        "southwest"    : __DIR__"shien",
        "southeast"    : __DIR__"shuode",
      ]));
  setup();
}

