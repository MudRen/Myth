//���߻���
//by junhyun
#include <ansi.h>

inherit ITEM;

int do_zhuan(string);
void create()
{
  set_name(HIW "���߻���" NOR, ({"guangming huizhang", "huizhang"}));
  set_weight(50);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "ö");
    set("long", HIW"�������ǻ�������Ļ���\n"NOR);
    set("value", 50000000);
    set("no_sell", 1);
  }
  
  setup();
}

void init()
{
        add_action("do_zhuan", "zhuan");
        call_out("announce",random(10),this_player());
}


void announce(object who)
{
    if(!this_object()) return;
    if(!who) return;
    CHANNEL_D->do_channel(this_object(), "rumor", 
            who->query("name")+"�õ���"+name()+"��\n");
}

int do_zhuan(string arg)
{
  object me = this_player();
  string msg; 
  if (!id(arg))
    return notify_fail("��Ҫתʲôְҵ��\n");

        message_vision(HIC"$N�����Ů���������$N�ɹ�תְΪ���ߣ�
\n"NOR, me);  
  
        me->add("bellicosity", -random( (int)me->query_kar() * 10));
        if ((int)me->query("bellicosity") < 0 ) me->set("bellicosity", 0);

        me->set("title", HIW"����"NOR);
        me->delete("betray");
        me->save();
        msg="��˵"+ me->query("name")+ "תְΪ�����ˣ�\n";
     CHANNEL_D->do_channel(this_object(),"rumor",msg);
  destruct(this_object());
  return 1;
}

