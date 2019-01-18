#include <mudlib.h>
#include <ansi.h>
#include <armor.h>
#include <dbase.h>
#include <command.h>
inherit CLOTH;
inherit F_SAVE;
inherit F_AUTOLOAD;
inherit F_DAMAGE;
string inputstr,verb;
int query_autoload()
{ return 1; }
void create()
{
  seteuid(getuid());
set("long",@LONG
    ����һ�������ħ��ʦ���磬Ϊ����ʦ�������㣬��ʦ�ǳ�����Ҫ���������
    �����ʦ����Ҫ�н�һ���Ĺ��ܻ�ӭ�ṩ
    ������д�Ĳ�����, ������ѶϢ����ʾ����һ�£�
    �������ӭ����ʦ(arch)�޸ĳɸ�����һ��
    ������ʦ(wizard)���Բ����б���, Ҳ���ǲ������Լ�Ŀ¼���б��ݻ��޸Ĺ���
    Ҳ��ϣ����ʦ����������, ����, ���ɸ������
    �����������ʮ�˲�������������һ���£�����жϱ�׼�ɴ���(admin)�ö�
    ����<help cloak>�Ի�ø������Ѷ��
LONG
);
  set("unit","��");
  set("material", "cloth");
   set("armor_prop/armor", 100000);
  set("armor_type", "cape");
  set("female_only", 1);
  set("light",1);
  setup();
}
void init()
{
  object me;
  seteuid(geteuid());
  me = this_player();
  if (me)
       set_name (HIW"����"NOR, ({ "xian yi", "cloth","pifeng" }));
  else
    set_name ("ħ��ʦ����", ({ "wiz cloak", "cloak" }));
  add_action("help","help");
  add_action("full","full");
  add_action("rem","rem");
  add_action("wave","wave");
  add_action("steal","steal");
  add_action ("whereis", "whereis");
  add_action ("pk_mob", "mobpk");
  add_action ("do_give", "give");
  add_action ("do_wakeup", "wakeup");
  add_action ("neili_quit", "fquit");
        add_action("do_sha", "K");
add_action("full", "full");
  this_player()->set_temp("heat",1);
}
int help(string str)
{
  if (str!="cloak") return 0;
write(@Help
    ������д�Ĳ�����, ������ѶϢ����ʾ����һ�£�
    �������ӭ����ʦ(arch)�޸ĳɸ�����һ��
    ������ʦ(wizard)���Բ����б���, Ҳ���ǲ������Լ�Ŀ¼���б��ݻ��޸Ĺ���
    Ҳ��ϣ����ʦ����������, ����, ���ɸ������
    �����������ʮ�˲�������������һ���£�����жϱ�׼�ɴ���(admin)�ö�
    �����ʹ�����µļ�������:
       % localcmd, stat, call, data, score, skills, �ȵ�
         ���� help wizcmds ȡ�ý�һ������
       wave <number> <type>             <<ȡ������Ǯ�ҵĶ�����Ŀ>
       rem <eqs> from <object>          <��ĳһ object ���װ��>
       mobpk <����1> with <����2>       <������1 ������2 �� k>
       whereis <���>                   <��ʾһ��ҵ����ڵ�>
       full <���>                      <ȫҽ, ��������������ڶ�Ϊ�Լ�>
       wakeup <���>                    <�ѻ��Բ��ѵ���ҽ���>
       sha <sb>                         <��ĳ���зǷ����ݵ���һص�ԭ״>
       <ע*>                            <���λ��ʦ����"sha"������>
Help
);
  return 1;
}
int rem(string str)
{
  string ob,player;
  object obj,npc;
  seteuid(geteuid());
  sscanf(str,"%s from %s",ob,player);
  if (!(npc = find_player(player)))
    if (!(npc = find_living(player)))
      if (!(npc = present(player, environment (this_player()))))
        return notify_fail ("[cloak]: û�����\n");
  obj=present(ob, npc);
  if(!obj)
    return notify_fail ("����û�����ֶ���\n");
  else {
//    message_vision ("$N��������һ�ӣ�"+npc->query("name")+"�Ͳ�������������$n��\n", this_player(), obj);
    obj->move(this_player());
    obj->move(npc);
    return 1;
  }
}
int steal (string str)
{
  string ob,player;
  object obj, npc, me;
  seteuid(geteuid());
  me = this_player();
  if (sscanf(str,"%s from %s",ob,player) != 2)
    return 0;
  npc = find_player (player);
  if (!(npc = find_player(player)))
    if (!(npc = find_living(player)))
      if ( !(npc = present(player, environment (me))) )
        return notify_fail ("û���"+str+"\n");
  // if(wiz_level(npc)>4) return notify_fail("��͵����Ķ������±��Ӱɡ�\n");
  if (!(obj=present(ob, npc)))
    return notify_fail ("û�������: "+ob+".\n");
  obj->move(me);
  message_vision ("$Nʩչ���ֿտ�֮�����ɹ���͵����"+npc->query("name")+"��"+obj->query("name")+"��\n", me);
  return 1;
}
int whereis(string arg)
{
  object where, me;
  object *ob;
  string msg;
  int i;
  me = this_player();
  if (arg) {
    where = environment(find_player(arg));
    if (!where) return notify_fail ("��������Ʈ��䡣\n");
    msg = where->query ("short")+"  -- "+file_name(where)+"\n";
    msg += where->query("long");
  }
  else {
    ob = users();
    msg = "";
    for(i=0; i<sizeof(ob); i++) {
      where = environment(ob[i]);
      if (!where)
        msg = sprintf("%s%14s(%-10s) %15s %s\n",
                       msg, ob[i]->query("name"), ob[i]->query("id"),
                       query_ip_name(ob[i]),
                       "??????????");
      else
        msg = sprintf("%s%14s(%-10s) %15s %s\n",
                       msg, ob[i]->query("name"), ob[i]->query("id"),
                       query_ip_name(ob[i]),
                       file_name(where));
      }
  }
  write (msg);
  return 1;
}
int full(string str)
{
  int max;
  object me;
  if (!geteuid()) seteuid (getuid());
  if(!str)
    me=this_player();
  else
    me=present(lower_case(str), environment(this_player()));
  if (!me) return notify_fail ("[cloak]: full error: �Ҳ���"+str+"\n");
max=me->query("max_sen");
me->set("eff_sen", max);
me->set("sen", max);
max=me->query("max_gin");
me->set("force", me->query("max_force"));
me->set("eff_gin", max);
me->set("mana", me->query("max_mana"));
me->set("atman", me->query("max_atman"));
me->set("gin", max);
max=me->query("max_kee");
me->set("eff_kee", max);
me->set("kee", max);
  max = me->max_food_capacity();
  me->set("food",max);
  max = me->max_water_capacity();
  me->set("water",max);
  me->clear_condition();
//   message_vision( "$N����������Ļظ����ģ� ���� ���� ����ķ  \n"+me->query("name")+"��ȫ������Ѹ�ٻָ��ˡ�\n",this_player());
  return 1;
}
int wave (string arg)
{
        string kind;
        int amount;
        object n_money;
        if( !arg || sscanf(arg, "%d %s", amount, kind)!=2 )
          return notify_fail("[cloak]: wave <����Ǯ> <Ǯ������>\n");
        n_money = present(kind + "_money", this_player());
        if( !n_money && file_size("/obj/money/" + kind + ".c") < 0 )
                return notify_fail("��ҡ�˰���ȴʲ��Ҳû�г�����\n");
        if( amount < 1 )
                return notify_fail("��ҡ�˰���ȴʲ��Ҳû�г�����\n");
        if( !n_money ) {
                n_money = new("/obj/money/" + kind);
                n_money->move(this_player());
                n_money->set_amount(amount);
        } else
                n_money->add_amount(amount);
message_vision( sprintf("$N��ʼʩչ�������ͻȻ�����%s%s%s��\n",
                        chinese_number(amount),
                        n_money->query("base_unit"),
                        n_money->query("name")),
                this_player());
        return 1;
}
int pk_mob(string str)
{
        object ob1,ob2;
        string st1,st2;
        if (!str || str=="") return notify_fail ("[cloak]: ������˭ PK ˭��\n");
        if (sscanf( str,"%s with %s",st1,st2)!=2 )
           return notify_fail ("mobpk <ob1> with <ob2>\n");
        if (!ob1=present(st1,environment(this_player())))
          return notify_fail("�Ҳ��� "+st1+" �������.\n");
        if (!ob2=present(st2,environment(this_player())))
          return notify_fail("�Ҳ��� "+st2+" �������.\n");
//        message_vision("$N�ó���������Ķ�������, ��"+
//                ob1->name()+"��"+ob2->name()+"��ʼ����걶���",
//                this_player());
        ob1->kill_ob(ob2);
        return 1;
}
int do_give (string str)
{
  object me, ob, who;
  string wiz, obs, whos;
  me = this_player();
  wiz = wizhood (me);
  if (sscanf (str, "%s to %s", obs, whos)!= 2)
    return 0;
  if (obs != "cloak" && obs != "wiz cloak") return 0;
  write ("my level : "+wiz_level(me)+"\n");
//  if (wiz_level(me) > 2)
  if ((wiz = SECURITY_D->get_boss(whos)) == "" || (wiz != me->query("id"))) {
    write ("�����粻�ܸ�����������ˡ�\n");
    return 1;
  }
  ob = present ("wiz cloak", me);
  if (!ob) write ("��û������������\n");
  who = find_player(whos);
  if (!who) write ("û������ˡ�\n");
  if (ob && who) {
    ob->move (who);
    message_vision ("$N��$nһ�����硣\n", me, who);
  }
  return 1;
}
int do_wakeup (string str)
{
  object me,who;
  me=this_player();
  if (!str) return notify_fail ("[cloak]: wakeup error, wakeup <someone>\n");
  if (!(who=present (lower_case(str), environment(this_player()))) )
    return notify_fail ("[cloak]: wakeup error, û��"+str+"\n");
   message_vision( "$N�����ص�����ӭ��һչ��ֻ��һ��������$n�����ӡ�\n"+
   "$n�����ָ���֪����\n",me,who);
  who->remove_call_out("revive");
  who->revive();
  who->reincarnate();
  return 1;
}
int neili_quit (string str)
{
  object ob, usr;
  seteuid(getuid());
  if (!str) return notify_fail ("[cloak]: Hey you! ������˭ quit ��\n");
  if (!(ob=find_player(str)))
    return notify_fail ("[cloak]: û�����("+str+")\n");
  if (objectp (ob))
    destruct( ob );
  else
    write ("[test] cloak: cannot neili quit\n");
  return 1;
}
int do_sha(string arg)
{
object ob, *skll;
int i;
mapping my, skl;
if(!arg||!ob=find_player(arg))
return notify_fail("��Ҫ��˭�����\n");
my=ob->query_entire_dbase();
skl=ob->query_skills();
skll=keys(skl);
ob->set("max_jing", 120);
ob->set("eff_jing", 120);
ob->set("jing", 120);
ob->set("max_qi", 120);
ob->set("eff_qi", 120);
ob->set("qi", 120);
ob->set("jingli", 0);
ob->set("neili", 0);
ob->set("eff_jingli", 0);
ob->set("max_jingli", 0);
ob->set("max_neili", 0);
ob->set("eff_neili", 0);
ob->set("combat_exp", 100);
my ["petential"] = 99;
for (i=0;i<sizeof(skll);i++)
{ while (skl[skll[i]]>5)
skl[skll[i]]--; }
ob->clear_condition();
message_vision("��������:���ͷ��ʼ�ɡ�\n", this_player(),ob);
return 1;
}
