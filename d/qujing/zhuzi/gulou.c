// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "��¥");
  set ("long", @LONG

��¥λ�����Ϲ��ĳ����ģ��˶���������������������ż���ɼ�һ
ЩУξ�������ߡ�������Ϧ�ֽ�ΪʳƷ���У���������һЩ��ݿ�
ջ���ϱ߿ɼ����Ϲ��ʹ�����¥������һ�ʰ�(huang bang)������
Χ�ۡ�

LONG);

  set("exits", ([ 
    "north" : __DIR__"zhuzi3",
    "south" : __DIR__"zhuzi4",
    "west" : __DIR__"xi4",
    "up" : __DIR__"jitan",
    "east" : __DIR__"tian1",
  ]));
  set("item_desc",([
   "huang bang" : "  ����ţ�������Ϲ���������²���\n"+
                  "  ������������վ���Ȭ����̫ҽԺ\n"+
                  "  δ�ܵ��ν���˰�����������ʿ��\n"+
                  "  �Ǳ��������޹�Ϊ�˳����Ź�����\n"+
                  "  ����\n",
  ]));
  set("objects", ([
    __DIR__"npc/taijian" : 3,
    __DIR__"npc/xiaowei" : 3,
  ]));
  set("outdoors", __DIR__"");
  setup();
}

void init ()
{
  add_action ("do_jiebang", "jiebang");
  add_action ("do_jiebang", "jie");
  remove_call_out ("sounding");
  call_out ("sounding",random(10),this_object());
}

void sounding (object where)
{
  string *msgs = ({
    "��¥�ϴ���������\n",
    "һ�������¥�ϴ�����\n",
    "�������ˡ�һ�����������\n",
    "��¥�������Ĺ����ڳ����Ͽջ��졣\n",
  });
  tell_room (where,msgs[random(sizeof(msgs))]);
}

int do_jiebang (string arg)
{
  message_vision ("$N��ϸ�ؽ����������\n",this_player());
  return 1;
}


