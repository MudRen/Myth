#include "where.h"

string ask_job()
{ 
  object  ob, me,gift,*team,obj;
  int exp,position,i;
  mapping target;
  string str;
  ob=this_player();
  me=this_object();
  exp=ob->query("combat_exp");
  if ((int)ob->query("level")<40)
       return "��ĵȼ�������\n";
  if (interactive(ob) && (int)ob->query_condition("hua_mission"))  
       return "����һ�ε�����û���!";
  if (interactive(ob) && (int)ob->query_condition("hua_busy"))  
       return "�����ҿ�û�и�������񣬵Ȼ������ɡ�\n";
  if ( !ob->query("wine/start") || !present("jiu pai",ob)) 
       return "������û��������㡣\n";
        if(exp<=200000)     
         return "����书̫����,����ǿ�������ɡ�\n";
        target = wheres[random(sizeof(wheres))];
    //for(i=100;i*i*i/10<=exp;i++); //i=maxpot
        if(random(10)>7)
        {obj=new(__DIR__"skiller"+sprintf("%d",random(3)+1));
         i=400+random(250);
         obj->do_copy(ob,i);
         obj->set("title",HIR"������"NOR);
        }
        else
        { obj=new(__DIR__"killer");
          i=400+random(200);
          obj->do_copy(ob,i);
        }
        obj->move(target["weizhi"]);
        obj->set_temp("must_killby",ob->query("id")); 
    ob->set_temp("hua_job_target", target["chinese"]);//where
    ob->apply_condition("hua_mission",30);
        command("nod");
        str="�����ӱ��ڡ�"+target["chinese"]+"��һ����������";
        command("say "+str);
    return "��ȥѲ��һ�¡�";
}

int accept_object(object who, object ob,object me)
{
        if ( ob->query("id") != "corpse") {
                command("say ������������?");
                return 0;
        }
        if ( !who->query_temp("hua_job_target") ) {
                command("say �ð��������������������");
                return 0;
        }
                if (ob->query_temp("must_killby")!= who->query("id")
                        ||ob->query("victim_user")||who->query_temp("hua_given") )
                {       command("shake");
                command("say ��ɱ�����ˡ�");
                return 0;
        } 

        who->set_temp("hua_given",1);
        call_out("destroying", 1, ob);
        call_out("ok", 1, who);
        return 1;
}

void ok(object who)
{
        int exp,pot,count,i;
        if (!who) return;
        command("pat" + who->query("id"));
        command("say ���ĺã����͸�!");
              who->clear_condition("hua_mission");
                who->delete_temp("hua_job_target");
                who->apply_condition("hua_busy",3+random(6));
             return;
}

void destroying(object obj)
{
        destruct(obj);
        return;
}

int ask_jiu()
{
         int tt; 
         object me,jiu;
         me=this_player();
         tt=me->query("wine/huangjiu");
         if (!me->query_temp("hua_given"))
            {command("say ��Ҫ����Ҫ�Ȱ�����Щ���顣\n");
             return 1;}
         if ( !me->query("wine/start") || !present("jiu pai",me)) 
            {command("say ����û�����־ơ�\n");
             return 1;}
         if( tt) 
         { if(tt<=time() && time()<tt+3600) 
        { message_vision("\n"+this_object()->query("name")+"˵�������Ҫ���ƣ��ȵ������ɡ�\n",me); 
            return 1; } 
        }
         jiu=new("/d/quest/wine/obj/huangjiu");
         jiu->move(me);
         me->set("wine/huangjiu",time());
         me->delete_temp("hua_given");
         command("say лл�����ץ�����ӱ������Ѿ����͸���ġ�");
         message_vision("$N����$nһ��"+jiu->query("name")+"��\n", this_object(),me);
         return 1;
}

string ask_fangqi()
{
         object me;
         me = this_player();
         if(!me->query_temp("hua_job_target"))
         return "��û��������,������Ϲ����ʲ��?";
         me->delete_temp("hua_job_target");
             return "û��ϵ,�´μ���Ŭ�� ��";
}
