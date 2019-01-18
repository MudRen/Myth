// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/sanqing.c

inherit ROOM;

void create ()
{
  set ("short", "�����");
  set ("long", @LONG

�������д������ͭ�ӣ��м���һʯ������������ɫ��ƿ����
ʯ��̨�����в��ٷ�ʢի�硣�ıڹ������ң����ķֱ���Ԫʼ
�����鱦������̫���Ͼ���

LONG);

  set("exits", ([
        "south"        : __DIR__"dianmen",
        "north"        : __DIR__"houdian",
        "northeast"    : __DIR__"xiang1",
      ]));
  set("objects",([
        __DIR__"npc/yuanshi" : 1,
        __DIR__"npc/lingbao" : 1,
        __DIR__"npc/taishang" : 1,
        __DIR__"obj/zhengsu" : 1,
      ]));
  setup();
}

void daoshi_appear(object who)
{
  remove_call_out ("daoshi_appearing");
  call_out ("daoshi_appearing",3,who);
}

void daoshi_appearing(object who)
{
  object shi;
  object where = this_object();

  if (where != environment(who))
    return;

  message_vision ("\n��ʿ���˹�����\n",who);
  message_vision ("��ʿ��״���ȵ������������Ĳ���������͵�Թ�Ʒ����\n",who);
  message_vision ("��ʿ�����ظ���$N�����һ���������������\n",who);
  shi = new("/d/qujing/chechi/npc/daoshi");
  shi->move(where);
  shi->set_leader(who);
  shi->kill_ob(who);
}

void daotong_appear(object who)
{
  remove_call_out ("daotong_appearing");
  call_out ("daotong_appearing",3,who);
}

void daotong_appearing(object who)
{
  object where = this_object();

  if (where != environment(who))
    return;

  message_vision ("\n��ͯ���˹�����\n",who);
  message_vision ("��ͯ��״�����û��Ҵ���һ������ʦ����ʥ�������ˣ���\n",who);
  message_vision ("ֻ����ͯһ��һ�������ȥ��\n\n",who);
  remove_call_out ("three_appearing");
  call_out ("three_appearing",3,who);
}

void three_appearing(object who)
{
  object yangli = new (__DIR__"npc/yangli");
  object huli = new (__DIR__"npc/huli");
  object luli = new (__DIR__"npc/luli");
  object where = this_object();

  if (where != environment(who))
    return;

  message_vision ("���������ﳾ���֡�\n",who);
  message_vision ("¹����������������\n",who);
  message_vision ("�����������ŷ��¸�����\n",who);
  yangli->move(where);
  huli->move(where);
  luli->move(where);
}
