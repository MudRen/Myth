inherit ROOM;

void create ()
{
  set ("short", "�ֵ�");
  set ("long", @LONG

����ɽ�ֽ���ɫ���������Ƿ������ޣ�����һ��������Ŀ��
�о���ԶԶ����ɽ��������¥̨ӰӰ����������
LONG);
 
  set("exits", ([
        "southup" : __DIR__"lingdao1",
        "north"  : __DIR__"lin7",
      ]));

  set("outdoors", __DIR__);

  setup();
}

