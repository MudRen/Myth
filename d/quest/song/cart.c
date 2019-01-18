// cart 
//by koker@sjsh 2002/04
#include <ansi.h>
inherit ITEM;

void to_rob();

mapping default_dirs = ([
        "north":        "����",
        "south":        "����",
        "east":         "����",
        "west":         "����",
        "northup":      "����",
        "southup":      "�ϱ�",
        "eastup":       "����",
        "westup":       "����",
        "northdown":    "����",
        "southdown":    "�ϱ�",
        "eastdown":     "����",
        "westdown":     "����",
        "northeast":    "����",
        "northwest":    "����",
        "southeast":    "����",
        "southwest":    "����",
        "up":           "����",
        "down":         "����",
        "enter":        "����",
        "out":          "����",
]);
void create()
{       
        seteuid(getuid());
        set_name(HIW"�˻���"NOR, ({ "huo che", "cart", "che"}) );
        set_weight(300000);
        set("no_get", 1);
 
set("location",1);
set("no_clean_up",1);

        set_max_encumbrance(80000000);
        set("unit", "��");
        set("long", "һ��������ƥ�Ļ���,�����gan che to(����)���������߶�\n");
        set("closed", 1);
        set("value", 2000);
    
}

void init()
{
    add_action("do_open","jie");
    if( this_player()->query_temp("in_dart"))
    {
         add_action("do_gan","gan"); 
         add_action("do_gan","drive");
    }
    call_out("destroy2",random(800)+1000,this_object());
}

int do_open(string arg)
{
        object me, ob;
        string mname,mid;
        mname = this_object()->query("master");
        mid = this_object()->query("masterid");
        me = this_player();
        ob = this_object();

        if(arg != "huo che")
          return notify_fail("��Ҫ��ʲô��\n");
        if(me->query_temp("in_dart"))
          return notify_fail("��������Ե���\n"); 
        if(present(mid,environment()))
          return notify_fail("�����Ļ����Աߣ��Ȱ��������ɡ�\n");

        message_vision("$N��$n�����ˡ�\n", me, this_object());
        message("channel:job",HIG"��"HIR"������"HIG"����"+mname
         +"�˵Ļ���"+me->query("name")+"��ȥ�ˣ�\n"NOR,users());
        call_out("destroy1",1,ob);
        return 1;
}

int do_gan(string arg)
{        
        object me,ob, env, obj;
        string item, dir, dest, target;
        mapping exit;
        me = this_player();
        ob = this_object();

        if(!arg) return notify_fail("��Ҫ��ʲô��\n");

        if( me->query("id")!=ob->query("masterid")) return 0;
        
        if( sscanf(arg, "%s to %s", item, dir) != 2 ||
                item != "cart" && item != "che")
                return command(query_verb()+" "+arg);
                        
        if( me->is_busy() )
                return notify_fail("��������æ������\n");

        if ( present("robbers",environment()))
                return notify_fail(HIR"�ٷ�����һ�����������ܣ�û��ô���ף���\n"NOR);
        
        if ( this_player()->is_fighting())
                return notify_fail("�㻹���ȰѶ��ֽ������˵�ɣ�\n");
 
        env = environment(me);
        if(!env) return notify_fail("��Ҫȥ���\n");
        
        if( !mapp(exit = env->query("exits")) || undefinedp(exit[dir]) ) {
                if( query_verb()=="gan")
                        return notify_fail("����������ȥ��\n");
                else
                        return 0;
        }
        
        dest = exit[dir];
                        
        if( !(obj = find_object(dest)) )
                call_other(dest, "???");
        if( !(obj = find_object(dest)) )
                return notify_fail("û���ϡ�\n");

        if( !undefinedp(default_dirs[dir]) )
                target = default_dirs[dir];
        else
                target = obj->query("short");

        message_vision(HIG "\n$N���Ż�����" + target + "ʻȥ��\n" NOR,
                me);
        message_vision(HIG "����¡¡��"+ target + "ʻȥ��\n" NOR,me);  

        if( ob->move(obj) && me->move(obj)) {
          all_inventory(env)->follow_me(me, dir);
          message_vision(HIG "$N���Ż���ʻ�˹�����\n" NOR,
                        me);
          message_vision(HIG "����¡¡ʻ�˹�����\n" NOR,me); 
          me->start_busy(random(3));
        }
        call_out("check1",1,ob,me);
        if (random(10)>4){ call_out("to_rob",1,me);}
        return 1;
}
int check1(object ob, object me)
{
        if (base_name(environment())==(string)me->query_temp("dart_area") 
             && present(me->query_temp("dart_id"), environment()) )
           {  
              message_vision(HIY"$N���˸����������ڰѻ��˵��˵�ͷ��\n\n"NOR,me);
              message_vision(HIY+me->query_temp("dart_name")+
                "����$N��ͷ˵������"+RANK_D->query_respect(this_player())
                +"�����ˣ���\n\n"NOR,me);
              write(HIY"�Ա߹��������˽���������ж�����˽�ȥ��\n"NOR);
              me->set_temp("over_dart",1);
              me->apply_condition("dart_limit", 0);
              call_out("destroy1",1,ob);
              return 1;
            }  
}
void destroy1(object me)
{
        
        destruct(me);
        return;
}

void destroy2(object me)
{
     message_vision(HIR"ͻȻ���Ӵ��һ�����������Ż������ˡ�\n"NOR,me);
  destruct(me);
  return;
}

void to_rob()
{
  object *ob;
  object robber,room;
  int i;
  room = environment(this_player());
  
  if( environment(this_player())->query("no_fight") ) return;
  message_vision(HIR"�ٷ�ͻȻ�Ӱ������˳�������Ц������������Ļ����������������ɣ�����\n" NOR,
        this_player()); 
        ob = all_inventory(environment(this_player()));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i])) continue;
                                ob[i]->set_leader(0);
                }
  this_player()->start_busy(2);
  if (random(7)==0)
  {
  robber=new(__DIR__"npc/robber0");
  }
  else if (random(7)==1)
  {
  robber=new(__DIR__"npc/robber1");
  }
  else if (random(7)==1)
  {
  robber=new(__DIR__"npc/robber2");
  }
  else if (random(7)==1)
  {
  robber=new(__DIR__"npc/robber3");
  }
  else if (random(7)==1)
  {
  robber=new(__DIR__"npc/robber4");
  }
  else if (random(7)==1)
  {
  robber=new(__DIR__"npc/robber5");
  }
  else if (random(7)==1)
  {
  robber=new(__DIR__"npc/robber6");
  }
  else
  {
  robber=new(__DIR__"npc/robber1");
  }
  robber->do_change(this_player());
  robber->move(room);
  robber->kill_ob(this_player());
  robber->checking(robber,this_player());
  robber->set_leader(this_player());
  robber->command("rob");
}
