// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "��ϼ��");
  set ("long", @LONG

��ϼ���ǳǱ�һ��������Ĵ������������ഫ�����Ϲ�������
���γǱ�ҹ��ϼ���������Ȼ��ʥ���ﻳ̥����̫�ӣ��ʽ��˽���
��Ϊ��ϼ����ʾ���顣�ϱ���һ�跿�����ơ�

LONG);

  set("exits", ([ 
    "west" : __DIR__"beixia1",
    "east" : __DIR__"beixia3",
    "south" : __DIR__"chafang",
  ]));
  set("outdoors", __DIR__"");
  setup();
}
