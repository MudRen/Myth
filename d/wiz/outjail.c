//outjail.c
//�쿴������player
// idea@yqyl

inherit ROOM;
#include <ansi.h>

string atime(int t);

void create()
{
        set("short","������");
        set("long", @LONG

������������ķ��䣬ͨ��������ʦ������쿴�����¼�ĵط�������������
���ǳ����ķ�ʽ��ֱ�ӱ��͵�������ʦ����������Բ쿴������ҵķ���
��¼(consult)���ı���������ʱ��(changetime id newtime)�ͷű�����
��(shifang��������)��

LONG );
	set("exits",([
		"enter" : __DIR__"qiushi",
                "east" : "/d/wiz/jijiu",
                "south" : "/d/wiz/wizroom",
	]));
	set("no_fight", 1);
	set("no_beg",1);
        setup();
}

void init()
{
	add_action("do_consult","consult");
	add_action("do_release","shifang");
	add_action("do_change","changetime");
}

int do_consult(string arg)
{
	int i,j,inage,howlong,mudage;
	object who;
	string rep,str,s;
	
	who = this_player();
	if(!wizardp(this_player())) return notify_fail("ֻ����ʦ���Բ쿴��¼\n");
	
	if (!arg) return notify_fail("consult <id>\n");
	who = find_player(arg);
	if (!who) return notify_fail("û������˻����ߡ�\n");
	rep = "\n";
	rep+= "�����������������������������������������������Щ�������������������\n";
	str = sprintf("%s %s(%s)",who->query("title"),who->query("name"),who->query("id"));
	rep+= sprintf("��%-44s���Ա�%-12s��\n",str,who->query("gender"));
	rep+= "�����������������������������������������������ة�������������������\n";
	if (!who->query("qiushi"))
	{
		rep+= "��"+HIW"������������¼"NOR+"����������������������������������������������������\n";
		rep+= "��������������������������������������������������������������������\n\n";
	} else
	{
		inage = who->query("qiushi/inage");
		howlong = who->query("qiushi/howlong");
		mudage = who->query("mud_age");
		
		if (file_name(environment(who))!="/d/wiz/qiushi")
		{
		rep+= "��"+HIW"�����ַ�����Ҳ"NOR+"����������������������������������������������������\n";
		rep+= "�����������������������������������Щ�������������������������������\n";
		}
		else
		{
		rep+= "��"+HIW"�������ڱ�����"NOR+"����������������������������������������������������\n";
		rep+= "�����������������������������������Щ�������������������������������\n";
		rep+= sprintf("���ѱ�����ʱ�䣺%-18s�����豻����%-20s��\n",atime(mudage-inage),
		atime(inage+howlong*60-mudage));
		rep+= "�����������������������������������੤������������������������������\n";
		}
		rep+= sprintf("���ܱ�����������%-16s�Ω��ܶ�ʱ�䣺%-18s�֩�\n",chinese_number(who->query("qiushi/times")),
		chinese_number(who->query("qiushi/totaltime")));
		rep+= "�����������������������������������ة�������������������������������\n";
		rep+= "�������������¼��                                                ��\n";
		rep+= "��������������������������������������������������������������������\n";
		
		str = who->query("qiushi/note");
		while ((i = strlen(str)) > 0)
  		{
    			j = strsrch (str, "\n");
    			if (j < 0)
    			{
      				s = str;
      				rep+= sprintf("��%s",s);
    			}  
    			s = str[0..j];
    			rep+= sprintf("��%s",s);
    			str = str[j+1..i];
  		}
		rep+= "��������������������������������������������������������������������\n\n";
		}
	write(rep);
	return 1;
}

string atime(int t)
{
	int d, h, m, s;
	string time;
	
	if (t<=0) return "����";
	s = t % 60;
	m = t /60;

/*
	if(d) time = chinese_number(d) + "��";
	else time = "";

	if(h) time += chinese_number(h) + "Сʱ";
*/	
	if(m) time = chinese_number(m) + "��";
	else time = "";
	time += chinese_number(s) + "��";

	return time;
}                                        

int do_release(string arg)
{
	string wizname,criname,result,ttime;
	object qiushi=load_object(__DIR__"qiushi");
	object me= this_player();
	object criminal;
	
	if(!wizardp(me)) return notify_fail("ֻ����ʦ���Է��ˣ�\n");
	if(!arg || !objectp(criminal = present(arg, qiushi)))
		return notify_fail("�����˭��\n");
	
	wizname = me->query("name") + "("+me->query("id")+")";
	criname = criminal->query("name") + "("+criminal->query("id")+")";
	
	ttime=ctime(time())[8..strlen(ctime(time()))];
	result = sprintf("%s  %s��%s���η���ų�\n",ttime,wizname,criname);
	
	criminal->set("qiushi/note",criminal->query("qiushi/note")+result);
	
	qiushi->takeout(criminal);
	qiushi->wizchannel(result);
	
        log_file("qiushi",result);
	
	return 1;
}

int do_change(string arg)
{
	string wizname,criname,result,ttime,id;
	object qiushi=load_object(__DIR__"qiushi");

	object me= this_player();
	object criminal;
	
	int otime,newtime;
	
	if(!wizardp(me)) return notify_fail("ֻ����ʦ���ԣ�\n");
	
	if(!arg || arg=="" || sscanf(arg, "%s %d", id, newtime)!=2)
		return notify_fail("ָ���ʽ : changetime <ĳ��> <�µ�ʱ��>\n");
	if(!objectp(criminal = present(id, qiushi)))
		return notify_fail("�����˭��\n");
	
	wizname = me->query("name") + "("+me->query("id")+")";
	criname = criminal->query("name") + "("+criminal->query("id")+")";
	
	ttime=ctime(time())[8..strlen(ctime(time()))];
	
	otime = criminal->query("qiushi/howlong");
	criminal->set("qiushi/howlong",newtime);
	
	result = sprintf("%s  %s��%sԭ����ʱ��%d�ָ�Ϊ%d��\n",ttime,wizname,criname,otime,
	newtime);
	
	criminal->set("qiushi/note",criminal->query("qiushi/note")+result);
	
	qiushi->wizchannel(result);
	
        log_file("qiushi",result);
	return 1;
}
