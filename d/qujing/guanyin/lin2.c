inherit ROOM;

void create ()
{
  set ("short", "�ֵ�");
  set ("long", @LONG

����ɽ�ֽ���ɫ���������Ƿ������ޣ�����һ��������Ŀ��
�о���ԶԶ����ɽ��������¥̨ӰӰ����������
LONG);
 
  set("exits", ([
        "northeast"      : __DIR__"lin1",
        "west"   :  __DIR__"lin3",
      ]));

  set("outdoors", __DIR__);

  setup();
}

