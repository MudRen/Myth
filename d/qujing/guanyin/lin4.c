inherit ROOM;

void create ()
{
  set ("short", "�ֵ�");
  set ("long", @LONG

����ɽ�ֽ���ɫ���������Ƿ������ޣ�����һ��������Ŀ��
�о���ԶԶ����ɽ��������¥̨ӰӰ����������
LONG);
 
  set("exits", ([
        "eastup"      : __DIR__"lin3",
        "westdown"   :  __DIR__"lin5",
      ]));

  set("outdoors", __DIR__);

  setup();
}

