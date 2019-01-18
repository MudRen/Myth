// created by snowcat
// 5/22/1997

string name_suffix();
string new_unit();

int display_info (object who)
{
  tell_object (who,"��ʹ�ã�transform <new-english-name> <��������>��\n");  
  return 1;
}

int change_success (object me, object ob)
{
  message_vision ("����δ�䣬ֻ��$N����ͻȻ���һ"+ob->query("unit")+
                  "$n��\n",me,ob);
  return 1;
}

int do_transform (string arg)
{
  string *msgs = ({
    "$Nץ��һ��$nһ���罫��ȥ�����������дʡ�\n",
    "$N��$n���ڿ��н���������һ�磬���һ����\n",
    "$N��$n������һ�������ڿ��кȵ������䡱��\n",
    "$N����$n������һ�ӣ��߹�����������ȥ��\n",
    "$N��$n������һ��������������������д����һ�硣\n",
  });
  object me = this_player();
  object ob = this_object();
  string id, name;

  if (!arg || sscanf(arg,"%s %s",id,name)!=2)
    return display_info(me);

  if (ob->query("has_transformed"))
    return 0;

  if (me->query_skill("spells")<10)
  {
    tell_object (me,"��ķ���������\n");
    return 1;
  }

  name = name + name_suffix();
  message_vision (msgs[random(sizeof(msgs))],this_player(),this_object());

  ob->set_name(name, ({"my "+id}));
  //ob->set_temp("apply/id",({id, "my "+id}));
  ob->set_temp("apply/id",({"my "+id}));
  ob->set("short",name+"("+capitalize("my "+id)+")");
  ob->set("unit",new_unit());
  ob->set("long","һ"+this_object()->query("unit")+name+"��\n");
  ob->set("has_transformed",1);

  call_out ("change_success",1,me,ob);
  return 1;
}

