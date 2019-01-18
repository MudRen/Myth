#include <skill.h>
#include <ansi.h>

inherit ITEM;
int random_go(object victim,string* dirs);
void doblow(object);

void create()
{
        set_name("�����編��", ({"wind seal", "seal", "paper"}));
	set_weight(100);
	if(clonep())
    		set_default_object(__FILE__);
  	else {

        set("long","һ�Ż����˷�����ҷ�ֽ�������и����ġ��硱�֡�\n");
        set("unit", "��");
        set("value", 0);
	set("no_put",1);
	set("no_sell",1);
	}
	setup();
}

void init()
{

  object me = this_object();
  object where = environment();

  if (userp(where))
  {
    if (me->query("owned"))
    {
      if (me->query("owned")!=where->query("id"))
      {
        call_out("destruct_me",1,where,me);
      }
    }
    else
    {
      me->set("owned",where->query("id"));
    }
  }
}

void destruct_me(object where, object me)
{
        object seal;
        if( seal=new("/obj/paper_seal"))
                seal->move(where);
	message_vision("$N���е�$nͻ����⣬���佥����ȥ�����ˡ�\n",where,me);
        destruct(me);
}

void invocation(object who)
{
	int i,a,b,c;
	
	a=who->query("combat_exp");
	b=(int)who->query_skill("spells")*(int)who->query_skill("spells")*(int)who->query_skill("spells");
	c=(int)who->query("mana_factor")*(int)who->query("mana_factor")*(int)who->query("mana_factor");
	i=a+b+c;

	this_object()->set("ap",i);
	return;
}
// modify by bird
int shot_ob(object victim)
{
	object seal=this_object();
	object me=this_player();
	object where=environment(me);

	int damage, ap, dp;
	
	if(me->is_busy())
		return notify_fail("����æ���أ��޷��������編����\n");
	if( !victim)
		return notify_fail("��������˲������\n");
	if( where->query("no_magic"))
		return notify_fail("���ﲻ�ܼ������編����\n");
	if( !me->is_fighting())
		return notify_fail("ֻ��ս���в��ܼ������編����\n");
	if( !userp(victim))
		return notify_fail("��ֻ�ܽ������編������������ϡ�\n");
	if( (int)me->query("mana") < 100 )
		return notify_fail("��ķ������ܿ��������編����\n");
	if( (int)me->query("sen") < 100 )
                return notify_fail("��ľ����㣬���Ѽ�Ԧ�����編����\n");

	message_vision(HIC"\n$N��һ�����š�����һ�ӣ�������һ��$n������\n"NOR, me, seal);
message_vision(HIC"$n��������һ�·ɵ���գ�ֻ��ƽ�ؿ��է�𣬼�ͷ���Ե�Ϯ��$N��\n"NOR, victim,seal);



	ap= (int)seal->query("ap");
	dp= (int)victim->query("daoxing")+(int)victim->query("combat_exp");
	dp+= (int)victim->query_skill("dodge")*(int)victim->query_skill("dodge")*(int)victim->query_skill("dodge")*(int)victim->query_kar()/20;


	if(random(ap+dp) > dp)	{

	message_vision(HIC"\n$N����һ�����ȣ�����ߵ����Ӱ���˳�ȥ��\n"NOR,victim);
			call_out("do_blow",1,victim);
			me->start_busy(2);
			victim->start_busy(2);
	}else{
		message_vision(HIC"\n˭֪$N����ʯ�����������Ϊ��������\n"NOR,victim);
		destruct(this_object());
	}
	
        if( !victim->is_fighting(me) ) {
                if( living(victim) ) {
                        if( userp(victim) ) victim->fight_ob(me);
                        else
				victim->kill_ob(me);
                }
                me->kill_ob(victim);
        }
	me->add("mana",-50);

        me->start_busy(2+random(2));

	return 1;
}

int shot (string target)
{
  object seal = this_object ();
  object me = this_player();
  string name=seal->query("name");
  object victim;

  if (!target)
    return notify_fail("�����˭��"+name+"��\n");

  victim=present(target,environment(me));
   return(seal->shot_ob(victim));
//  return 1;
}

void do_blow(object victim)
{
	string* dirs
	=({"/d/qujing/bibotan/", "/d/qujing/baotou/", "/d/qujing/baoxiang/",
"/d/qujing/biqiu/", "/d/qujing/chechi/", "/d/qujing/dudi/", "/d/qujing/fengxian/",
"/d/qujing/firemount/", "/d/qujing/jilei/", "/d/qujin/jindou/", "/d/qujing/jingjiling/",
"/d/qujing/jinping/", "/d/qujing/jisaiguo/", "/d/qujing/maoying/", "/d/qujing/jisaiguo/",
"/d/qujing/qilin/", "/d/qujing/pansi/", "/d/qujing/pingding/", "/d/qujing/qinfa/",
"/d/qujing/qinglong/", "/d/qujing/tontian/", "/d/qujing/wudidong/", "/d/qujing/wuji/",
"/d/qujing/xiaoxitian/", "/d/qujing/yinwu/", "/d/qujing/yuhua/", "/d/qujing/zhujie/",
"/d/qujing/zhuzi/" });

	random_go(victim,dirs);
	destruct(this_object());
	return;
}
int random_go(object victim, string* dirs)
{
        int             i, j, k;
        object  newob;
        mixed*  file;

        if( !sizeof(dirs) )  return 1;

    i = random(sizeof(dirs));    // pick up one directory

        file = get_dir( dirs[i]+"*.c", -1 );
        if( !sizeof(file) )             return 1;

        k = sizeof(file);
        while(1)  {
           j = random(k);
           if( file[j][1] > 0 )         break;          // pick up a file with size > 0
        }
    if( (newob=load_object(dirs[i]+file[j][0])) )   {
                victim->move( newob ); 
        }
        else  {
		       random_go(victim,dirs);
        }

        return 0;
}

