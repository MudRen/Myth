// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

��ѹѹԶԶһƬ���ӣ���ľï�ܣ��Ӳ������ظߡ���ʯ������
һ��������С·��·����ʯ�߸ߵ͵͵��̿����紵�ݶ����·�
�������۾��ڰ��������㡣

LONG);

  set("exits", ([
        "northdown"   : __DIR__"shan12",
        "southeast"   : __DIR__"wulin2",
      ]));
  set("outdoors", __DIR__);

  setup();
}



