// created by snowcat.c 4/4/1997
// room: /d/nuerguo/townc3.c

inherit ROOM;

void create ()
{
  set ("short", "ɣ���ﶫ");
  set ("long", @LONG

�������������ɣ���ﶫ����������Ů������Ҫ��������
������������������ٶ���Ů�ˡ���������ߵ��ο�����
���������οͣ�Ů���Ƕ���ϲ��ӵ�Ͻ�ͷߴߴ������������
�����۸���ͣ��

LONG);

  set("exits", ([ 
        "north" : __DIR__"townb3",
        "west"  : __DIR__"townc2",
        "southeast" : __DIR__"sanchalu",
      ]));
  set("outdoors", __DIR__"");

  setup();
}






