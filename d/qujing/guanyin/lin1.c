inherit ROOM;

void create ()
{
  set ("short", "�ֵ�");
  set ("long", @LONG

����ɽ�ֽ���ɫ���������Ƿ������ޣ�����һ��������Ŀ��
�о���ԶԶ����ɽ��������¥̨ӰӰ����������
LONG);
 
  set("exits", ([
        "northeast"      : "/d/westway/jiayu",
        "southwest"   :  __DIR__"lin2",
      ]));

  set("outdoors", __DIR__);

  setup();
}

