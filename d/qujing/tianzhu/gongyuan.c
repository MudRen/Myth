// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "��Ժ");
  set ("long", @LONG

��Ժ���ʻ��ٲݴԴԣ�Ժ����������ɫ��ʯ�ӣ�һ�������Զ�
������������ͨ�������ȵĶ���ͨ���ĸ󣬲��ȵ�����ͨ��
��������

LONG);

  set("exits", ([
        "east"   : __DIR__"huayi",
        "west"   : __DIR__"zhaoyang",
      ]));
  set("outdoors", __DIR__);

  setup();
}


