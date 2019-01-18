#include <ansi.h>
inherit ROOM;
inherit F_SAVE;
string SAVE_NAME;

void reload(string savename)
{
SAVE_NAME=savename;
if(!restore())     
log_file("city_save",sprintf("Failed to restore(%s)     %d.\n",savename,time()));
}   

string query_save_file()
{
	string id;
    id = SAVE_NAME;
	if( !stringp(id) ) return 0;
	return sprintf(DATA_DIR "city/%s",id);
}
void init()
{
       add_action("do_tax", "tax");
	add_action("do_attack", "attack");
	add_action("do_defend", "defend");
	add_action("do_status", "status");
	add_action("do_kaifa", "kaifa");
	add_action("do_fangqi", "tuibing");
       add_action("do_zhuza","zhuza");
       add_action("do_combat","zhenyuan");
       add_action("do_true","true");
        set("no_clean_up", 1);
}

int do_tax(string arg)
{
object me=this_player();
int pts; 
if(me->query("id")!=this_object()->query("owner")) return notify_fail("�㲻�ǳ��������ܹ���˰��\n");
if(this_object()->query("taxing")> (int)time()) return notify_fail("����˰���ã���һ��������˵�ɣ������������ˡ�\n");
if( !arg || !sscanf(arg, "%d", pts)) return notify_fail("�����˰�ʣ�tax <˰��> (0~100������)\n");
if(pts<0 || pts >100) return notify_fail("�����˰�ʣ�tax <˰��> (0~100������)\n");
if((query("tax")!=0)&& pts==0) 
{
tell_object(me,"��ȡ����"+this_object()->query("short")+"��˰�գ����ն���м���֡��ҳ϶�������.\n"); 
this_object()->add("faith",20);
message("vision",HIY+"����͢������:"+NOR+HIC+me->query("name")+
"ȡ����"+this_object()->query("short")+"��˰�ա�\n"+NOR,users());
return 1;
}
tell_object(me,"�㽫"+this_object()->query("short")+"��˰����Ϊ"+pts+"%.\n");
if( this_object()->query("tax")> pts) 
{
 tell_object(me,"���ն��㽵��˰�ʵ��������Ǹм����ҳ϶�������.");
this_object()->add("faith",(this_object()->query("tax")-pts)/10+random(2));
this_object()->add("people",this_object()->query("people")*(this_object()->query("tax")-pts)/100);
}
if(this_object()->query("tax") < pts)
{
tell_object(me,"���ն����˰���������ǻ��ɡ��ҳ϶��½���.\n");
 this_object()->add("faith",-(this_object()->query("tax")-pts)/10);
this_object()->add("people",this_object()->query("people")*(this_object()->query("tax")-pts)/100);
}
if(this_object()->query("faith")>100) this_object()->set("faith",100);
this_object()->set("tax",pts);
this_object()->set("taxing",time()+36000); //ÿ��ʮ��Сʱ������˰��
save();
return 1;
}



int do_attack()
{
object who,haha=this_object();
object me=this_player();
int ap;
if(me->query("id")==this_object()->query("owner"))
return notify_fail("���������Լ��ļ�԰�ģ�\n");
if(!this_object()->query("owner"))
{
tell_object(me,"����һ���ճǣ����ʿ������һ��һ������ҡ��ڵ����˳ǡ�\n");
message("vision",HIY+"��ս��׷ɡ�:"+NOR+HIC+me->query("name")+"��ռ��"+
this_object()->query("short")+"\n"+NOR,users());
this_object()->set("owner",me->query("id"));
save();
return 1;
}                      //������ռ��ĳ���
who=find_player(this_object()->query("owner"));
if(!who) return notify_fail("���е����˲����ߣ��㲻�ܹ������ĳ��С�\n");
ap=me->query("soilder")*me->query("train_level");
if(ap<=0) return notify_fail("����Ĳ�����������̡�����Ϊ����˭ѽ��\n");
tell_object(who,me->query("name")+"Ҫ�������"+this_object()->query("short")+"�ˡ���Ͻ��ɱ�֧Ԯ��\n");
message("vision",HIY+"��ս��׷ɡ�:"+NOR+HIC+me->query("name")+"��"+
this_object()->query("short")+"��ٽ�����\n"+NOR,users());
me->set("attacking",1);
this_object()->set("attacker",me->query("id"));
this_object()->set("receive_attack",1);
me->fight_ob(haha);
return 1;
}

int do_zhuza(string arg)
{
int pts;
object me=this_player();
if(me->query("id") != this_object()->query("owner"))
return notify_fail("ֻ�г�������פ�������������\n");
if( !arg || !sscanf(arg, "%d", pts)) return notify_fail("ָ���ʽ��zhuza <����> (����)\n");
if(pts <=0) return notify_fail("�ߺߣ��˻��и���ô��\n");
if(pts > me->query("soilder")) 
return notify_fail("��û����ô��ʿ�������䡣\n");
tell_object(me,"�㽫����ʿ��������һ��פ���������\n");
this_object()->add("soilder",pts);
this_object()->set("train_level",me->query("train_level"));
me->add("soilder",-pts);
message("vision",HIY+"����͢������:"+NOR+HIC+me->query("name")+"��פ��"+chinese_number(pts)+
"��ʿ������"+this_object()->query("short")+".\n"NOR,users());
save();
return 1;

}

int do_combat(string arg)
{
object me=this_player(),who;
int pts,train1;
if( !arg || !sscanf(arg, "%d", pts)) return notify_fail("ָ���ʽ��zhenyuan <����> (����)\n");
if(pts > me->query("soilder"))
return notify_fail("��û����ô��ʿ������ָ�ɡ�\n");
train1=pts*me->query("train_level")+this_object()->query("soilder")*this_object()->query("train_level");
train1=train1/(pts+this_object()->query("soilder"));
tell_object(me,"������"+chinese_number(pts)+"��ʿ����Ԯ"+this_object()->query("short")+".\n");
who=find_player(this_object()->query("owner"));
if(who)
if(me != who)
tell_object(who,me->query("name")+"����"+chinese_number(pts)+"��ʿ����Ԯ"+this_object()->query("short")+".\n");
message("vision",HIY+"��ս��׷ɡ�:"+NOR+HIC+me->query("name")+"����"+chinese_number(pts)+
"��ʿ��������Ԯ"+this_object()->query("short")+".\n"NOR,users());
this_object()->add("soilder",pts);
this_object()->set("train_level",train1);
me->add("soilder",-pts);
save();
return 1;
}

int do_kaifa(string arg)
{
object me=this_player();
if(me->query("id") != this_object()->query("owner"))
return notify_fail("ֻ�г������ܿ�����\n");
if(!arg)
{
printf("ũҵ������(farm):"+this_object()->query("farm")+"    ��ҵ������(trade):"+this_object()->query("trade")+
"\n���з�����(defendance):"+this_object()->query("defendance")+"\n");
return 1;
}
if((arg != "farm")&&(arg != "trade")&&(arg != "defendance"))
return notify_fail("Ŀǰֻ�����ֿ�����Ŀ��ũҵ(farm),��ҵ(trade),����(defendance).\n");
if(me->query("balance") < (this_object()->query(arg)+1)*10000)
return notify_fail("����ʽ��㣬�����ȶ�׬��Ǯ�ɡ�\n");
if(arg=="farm")
{
 tell_object(me,this_object()->query("short")+"��ũҵ�����������ˡ�\n");
if(random(3))
if(this_object()->query("faith") <100)
{
tell_object(me,this_object()->query("short")+"������ҳ϶������ˡ�\n");
this_object()->add("faith",1);
}
this_object()->add("farm",1);
this_object()->add("people",1000+random(500));
}else
if(arg=="trade")
{
 tell_object(me,this_object()->query("short")+"����ҵ�����������ˡ�\n");
if(random(4))
if(this_object()->query("faith") <100)
{ 
tell_object(me,this_object()->query("short")+"������ҳ϶������ˡ�\n");
this_object()->add("faith",1);
}
this_object()->add("trade",1);
this_object()->add("people",2000+random(500));
}else
{
tell_object(me,this_object()->query("short")+"�ĳ��з����������ˡ�\n");
this_object()->add("defendance",1);
}
me->add("balance",-10000*this_object()->query(arg));
save();
return 1;
}

int do_status(string arg)
{
object me=this_player();
object ob;
string one;
if(this_object()->query("faith")<10) one="���ﲻ֪Ϊ������������һ�ֻֿŵ����գ�ҥ���Ĳ�������˼�䡣\n";
else if(this_object()->query("faith")<30) one="����һƬ���ţ�Ȼ���ǲ����ǰ��꣬Ҳ���������Ƕ���˭�������Ѿ���ľ��\n";
else if(this_object()->query("faith")<50) one="�����Ƕ��ڳ�������˵û���ڴ����������û�������Ļ��������ڴ��ܿ�ͻ���ʧ�ġ�\n";
else if(this_object()->query("faith")<70) one="�����Ƕ��ڳ���������ģ��������������ʵ������ǻ���ס��������\n";
else one="�������ж��ǳ����Ŀ���׷���ߣ�����Ϊ������Ĥ�ݣ��治֪����ʹ����ʲô�ֶΣ�����������ڶ�����ġ�\n";

if(this_object()->query("farm")<10) one +="�������۶��ǻ��ߵ�Ұ�أ�����Ӱ����ÿһ���ˡ�\n";
else if(this_object()->query("farm")<30) one +="����ũ�����������������أ�������ճɣ����������϶�Ƥ�أ�\n";
else if(this_object()->query("farm")<50) one +="һƬƬ��ũ��ɢ���ڻ�Ұ�ϣ����ܿ����������������⣬���������Ѿ����ö����ˡ�\n";
else if(this_object()->query("farm")<70) one += "��������ũҵ�ƺ������ӣ����޷�ʵ�����Է��á�\n";
else one +="��İ��֯�������ݺᣬ����Ʈ�㣬�������ˣ���һ����԰��⣬���Ƿ�����ʳ��������ҵ��\n";

if(me->query("id") != this_object()->query("owner")) 
{
printf("                   "+this_object()->query("short")+"\n"+one+
"�˿ڣ�"+this_object()->query("people")+"         ˰�ʣ�"+this_object()->query("tax")+"\n"+
"ũҵ�����ȣ�"+this_object()->query("farm")+"  ��ҵ������:"+this_object()->query("trade")+"\n"+
"�����ȣ�"+this_object()->query("defendance")+"      ����:"+this_object()->query("owner")+"\n");
return 1;
}
printf("                   "+this_object()->query("short")+"\n"+one+
"�˿ڣ�"+this_object()->query("people")+"        ˰�ʣ�"+this_object()->query("tax")+"\n"+
"ũҵ�����ȣ�"+this_object()->query("farm")+"  ��ҵ������:"+this_object()->query("trade")+"\n"+
"�����ȣ�"+this_object()->query("defendance")+"      �ҳ϶�:"+this_object()->query("faith")+"\n"+
"פ������:"+this_object()->query("soilder")+"     פ��ѵ����:"+this_object()->query("train_level")+"\n");
return 1;
}

int do_fangqi(string arg)
{
object me=this_player();

if(me->query("id") == this_object()->query("owner"))
{
tell_object(me,"�����Ҫ���������ǳ���(true)\n");
me->set("ready_fangqi",1);
return 1;
}
 
if( !me->query("attacking") )
return notify_fail("�����ڲ�û�й���ѽ��\n");
me->remove_enemy(this_object());
me->delete("attacking");
this_object()->delete("receive_attack");
this_object()->delete("attacker");
tell_object(me,"�����ͷ���ԣ�һ�����£������ձ���\n");
message("vision",HIY+"��ս��׷ɡ�:"+NOR+HIC+me->query("name")+"ȡ���˶�"+this_object()->query("short")+
"�Ľ������Զ��˱���.\n"NOR,users());
save();
return 1;
}

int do_true(string arg)
{
int soilder,train;
object me=this_player();

if(!me->query("ready_fangqi"))
return notify_fail("ʲô��\n");

tell_object("���Զ������˶�"+this_object()->query("short")+"��ͳ�Ρ�\n");
train=this_object()->query("train_level");
soilder=this_object()->query("soilder");
if(soilder)
tell_object(me,"�㽫�����"+chinese_number(soilder)+"��ʿ�����¹������¡�\n");
this_object()->set("soilder",0);
train=soilder*this_object()->query("train_level")+me->query("soilder")*me->query("train_level");
train=train/(soilder+me->query("soilder"));
me->add("soilder",soilder);
me->set("train_level",train);
this_object()->set("train_level",0);
this_object()->delete("owner");
message("vision",HIY+"����͢������:"+NOR+HIC+me->query("name")+"�Զ������˶�"+this_object()->query("short")+
"��ͳ�Σ������˸ó�.\n"NOR,users());
save();
return 1;
}

int do_defend(string arg)
{
object me=this_player();
object who;
int one,two,three;
if(me->query("id")!= this_object()->query("owner"))
return notify_fail("�㲻�ǳ�����\n");

if(!this_object()->query("receive_attack"))
return notify_fail("��û���⵽����ѽ��\n");
if(!arg)
{
printf("Ŀǰ���õķ�����ʩ��:��ľ��ʯ(stone),����(arrow),����(fire)\n");
return 1;
}
if(me->is_busy()) return notify_fail("��һʱ��æ���ң���Ȼ��֪�����ָ�Ӳźá�\n");

who=find_player(this_object()->query("attacker"));
if(!who) return 1;

one=this_object()->query("defendance")+this_object()->query("faith")+this_object()->query("train_level");
one=one*this_object()->query("soilder");
if(one< 0) one=0;
two=who->query("soilder")*who->query("train_level");
three=who->query("soilder")-this_object()->query("soilder");
if(three <0) three= -1*three;
if(arg=="stone")
if(random(one)> random(two))
{
message_vision(HIC"$N��ʿ��ߺ���Ž�������ʯ�ӳ�ǽ����������$nһʱ������ʿ�����˲��١�\n"NOR,me,who);
message("vision",who->query("name")+"��ʧʿ��"+chinese_number(random(three/10))+"����\n", ({ me,who})); 
me->start_busy(random(5)+1);
return 1;
}

if(arg=="arrow")
if(random(one)>3*random(two))
{
message_vision(HIC"����һ�������죬�Ӽ�������������ʿ��������ɻȣ�$n��ʿ��������һƬ��\n"NOR,who);
message("vision",HIC+who->query("name")+"��ʧʿ��"+chinese_number(random(three/10))+"����\n"NOR, ({ me, who })); 
me->start_busy(random(10)+2);
return 1;
}

if(arg=="fire")
if(random(one)>5*random(two))
{
message_vision(HIC"$N��У��Ż𡢷Ż𡣳�����������ȼ�ŵĻ�ѣ��ҽ����У�$n��ʿ���������ڡ�\n"NOR,me,who);
message("vision",HIC+who->query("name")+"��ʧʿ��"+chinese_number(random(three/10))+"����\n"NOR, ({ me,who })); 
me->start_busy(random(15)+3);
return 1;
}
message("vision",HIC+who->query("name")+"ȴ���з�����û���ܵ���ʧ��\n"NOR, ({ me, who})); 
me->start_busy(random(5)+1);
return 1;
}

