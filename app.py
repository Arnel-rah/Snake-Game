
import sys
import time
import math

def gradient_text(text):
    """Renvoie le texte coloré en dégradé ANSI (approx)."""
    out = []
    length = max(1, len(text))
    for i, ch in enumerate(text):
        t = i / length
        r = int((math.sin(2 * math.pi * t) * 127) + 128)
        g = int((math.sin(2 * math.pi * t + 2) * 127) + 128)
        b = int((math.sin(2 * math.pi * t + 4) * 127) + 128)
        out.append(f"\033[38;2;{r};{g};{b}m{ch}")
    out.append("\033[0m")  
    return "".join(out)

def progress_bar(total=30, delay=0.04):
    """Barre de progression simple et fluide."""
    for i in range(total + 1):
        ratio = i / total
        filled = int(ratio * 30)
        bar = "█" * filled + "─" * (30 - filled)
        percent = f"{int(ratio * 100):3d}%"
        # couleur en fonction du ratio (du rouge au vert)
        r = int(255 * (1 - ratio))
        g = int(255 * ratio)
        sys.stdout.write(f"\r\033[48;2;{r};{g};0m {bar} \033[0m {percent}")
        sys.stdout.flush()
        time.sleep(delay)
    print()  # saut de ligne final

def sparkle(message, times=6, delay=0.25):
    """Affiche un message qui scintille (alternance couleurs / style)."""
    styles = [
        "\033[1m",      # bold
        "\033[3m",      # italic (si supporté)
        "\033[7m",      # inverse
        "\033[4m",      # underline
        "\033[9m",      # strike (selon terminal)
        ""              # normal
    ]
    for i in range(times):
        style = styles[i % len(styles)]
        print(f"\r{style}{gradient_text(message)}\033[0m", end="", flush=True)
        time.sleep(delay)
    print("\n")

def main():
    title = "Bienvenue dans mon script ✨"
    print("\n" + gradient_text(title) + "\n")
    subtitle = "Préparation en cours — restez cool 😎"
    print(gradient_text(subtitle))
    print()
    progress_bar(total=40, delay=0.03)

    sparkle("Prêt ! 🚀 Merci d'avoir lancé ceci.")

    # Petit menu interactif démonstratif
    print("Choisis une option :")
    print("  1) Dire bonjour")
    print("  2) Afficher l'heure")
    print("  3) Quitter")
    choice = input("> ").strip()
    if choice == "1":
        name = input("Ton nom ? ").strip() or "Ami"
        print(gradient_text(f"Salut, {name} — code et café ☕"))
    elif choice == "2":
        print("Heure locale :", time.strftime("%Y-%m-%d %H:%M:%S"))
    else:
        print("À bientôt 👋")

if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        print("\nInterrompu — à la prochaine !")
