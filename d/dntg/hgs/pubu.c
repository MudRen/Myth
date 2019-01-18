//sgzl

inherit ROOM;

void create ()
{
  set ("short", "�ٲ�ǰ");
  set ("long", @LONG

ֻ���ǹɽ�ˮ����������ƹ���ӿ����˳����ɽ��ֱ��Դ��֮����
����һ���ٲ���Ȫ�������ǣ�

����һ�ɰ׺���ǧѰѩ�˷ɣ����紵���ϣ������ջ�����
�������������֣��������΢���������ٲ������ƹ���ᡡ�
LONG);


  set("exits", ([
            "west"   : __DIR__"shanya",
      ]));
  set("outdoors", 1);

  setup();
}

void init ()
{
  object who = this_player();
      
  add_action("do_jump", "jump");
  add_action("do_wave", "wave");

  if (who && interactive(who))
    call_out ("appearing", 1, who);
}

void appearing (object who)
{
  object me =this_player();
  object where = this_object();
  object houzi;

  if (! who ||
        environment(who) != where)
    return;

  if (! present ("hou zi 4", where))
  {
    houzi = new (__DIR__"npc/hou");
    houzi->move(where);
    message_vision ("�����дڳ�һֻ$N��\n",houzi);
  }


}


int do_jump(string arg)
{
        object me;

        me = this_player();
        if ( !arg || ( arg != "pubu" ) ) return  notify_fail("�����Ķ�����\n");

        else if ( random(30)+me->query("kar") < 30 )
//        else if ( (random(10)+me->query("kar")+me->query("donation/1000000")) < 40 )
          { 
          message_vision("$N����һ�ݣ���С��ײ����һ��ʯͷ�ϡ�\n", me);
          me->unconcious();
          }

        else
          {
          message_vision("$N���һ��������ȥ���ƣ���˵�շ���Ծ���ٲ���\n", me);
          me->move(__DIR__"pubu1");
          }

        return 1;
}

int do_wave(string arg)
{
        object me,who;
        object where = this_object();
        object hb = this_object();

        me = this_player();
        if ( !arg || ( arg != "flag" ) ) return  notify_fail("�������ʲô��\n");

        else if (!(hb=present(arg, me))) 
           return notify_fail("������û���ⶫ����\n");
    
        else 
          { 
          message_vision("$N�����������ӣ����һ���������컯�����컯������ûˮ��ԭ����һ�������š����Ǳ���һ���������ļҵ����ֵ��ǿ�ȥѽ����\n", me);
          call_out("jumping",2,me);
          if(me->query("dntg/huaguo")!="done")  me->set("dntg/huaguo", "allow");
          destruct(hb);
          }

        return 1;
}

void jumping(object who)
{
  object where = this_object();
  object who1 = present ("hou zi 1",where);
  object who2 = present ("hou zi 2",where);
  object who3 = present ("hou zi 3",where);
  object who4 = present ("hou zi 4",where);
  destruct(who1);
  destruct(who2);
  destruct(who3);
  destruct(who4);
  message_vision("�������������ȿֺ�������ٲ���\n", who);
}
