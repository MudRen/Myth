// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "������");
  set ("long", @LONG

������Ϊ������ͨ������Ϊ��ʥ������Ϊ��ʥ���м�Ϊ��ʥ������
�����ޱȽ������Ƕ���ܣ����������Ϻ������̺�����߸�������
˿�������ỺƮ����

LONG);
  set("exits", ([ 
    "northwest" : __DIR__"neiyuan",
    "northeast" : __DIR__"nei",
    "west" : __DIR__"zhaoyang",
  ]));
  setup();
}
